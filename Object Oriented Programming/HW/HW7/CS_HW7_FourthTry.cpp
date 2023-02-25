#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

// int totalAnt = 0;
// int totalDoodlebug = 0;

class Organism {
protected:
    int character;
    int coorX;
    int coorY;
    int breedCount;
public:
    Organism();
    Organism(int newCharacter, int newX, int newY);
    int getCharacter();
    virtual void move(Organism* grid[20][20]);
    virtual void breed();
    virtual void starve();
    int getBreedCount();
};

Organism::Organism() {
    character = 45;
    coorX = -1;
    coorY = -1;
    breedCount = 0;
}

Organism::Organism(int newCharacter, int newX, int newY) {
    character = newCharacter;
    coorX = newX;
    coorY = newY;
    breedCount = 0;
}

int Organism::getCharacter() {
    return character;
}

//--------------------------------------------------------------------------------------------------------------
// Forward Declaration

vector<int> availableCells(Organism* grid[20][20], int x, int y);
bool cellCondition(Organism* grid[20][20], int x, int y);
bool isAnt(Organism* grid[20][20], int x, int y);

//--------------------------------------------------------------------------------------------------------------

void Organism::move(Organism* grid[20][20]) {
    int direction = rand() % 4 + 1;
    
    if (direction == 1) { // right
        // cout << "right" << endl;
        // cout << "Coor: " << grid[coorX][coorY+1]->getCharacter() << endl;
        if (cellCondition(grid, coorX, coorY+1) == true) {
            Organism* temp = new Organism;
            grid[coorX][coorY] = temp;
            coorY += 1;
            grid[coorX][coorY] = this;
        }
    } else if (direction == 2) { // left
        // cout << "left" << endl;
        // cout << "Coor: " << grid[coorX][coorY-1]->getCharacter() << endl;
        if (cellCondition(grid, coorX, coorY-1) == true) {
            Organism* temp = new Organism;
            grid[coorX][coorY] = temp;
            coorY -= 1;
            grid[coorX][coorY] = this;
        }
    } else if (direction == 3) { // down
        // cout << "down" << endl;
        // cout << "Coor: " << grid[coorX+1][coorY]->getCharacter() << endl;
        if (cellCondition(grid, coorX+1, coorY) == true) {
            Organism* temp = new Organism;
            grid[coorX][coorY] = temp;
            coorX += 1;
            grid[coorX][coorY] = this;
        }
    } else { // up
        // cout << "up" << endl;
        // cout << "Coor: " << grid[coorX-1][coorY]->getCharacter() << endl;
        if (cellCondition(grid, coorX-1, coorY) == true) {
            Organism* temp = new Organism;
            grid[coorX][coorY] = temp;
            coorX -= 1;
            grid[coorX][coorY] = this;
        }
    }
}

void Organism::breed() {}

void Organism::starve() {}

int Organism::getBreedCount() {
    return breedCount;
}


//--------------------------------------------------------------------------------------------------------------

class Ant : public Organism {
public:
    Ant();
    Ant(int newX, int newY);
    void move(Organism* grid[20][20]);
    void breed(Organism* grid[20][20]);
};

Ant::Ant() {
    // Organism(111, -1, -1);
    character = 111;
    coorX = -1;
    coorY = -1;
    breedCount = 0;
    // totalAnt += 1;
}

Ant::Ant(int newX, int newY) {
    // Organism(111, newX, newY);
    character = 111;
    coorX = newX;
    coorY = newY;
    breedCount = 0;
    // totalAnt += 1;
}

void Ant::move(Organism* grid[20][20]) {
    Organism::move(grid);
    breedCount += 1;
    if (breedCount == 3) { 
        breed(grid);
        breedCount = 0;
    }
}

void Ant::breed(Organism* grid[20][20]) {
    vector<int> cells = availableCells(grid, coorX, coorY);
    if (cells.size() != 0) {
        int num = rand() % (cells.size()/2);
        int tempX = cells[num*2];
        int tempY = cells[num*2+1];
        Ant* temp = new Ant(tempX, tempY);
        grid[tempX][tempY] = temp;
    }
}

//--------------------------------------------------------------------------------------------------------------

class Doodlebug : public Organism {
    int starveCount;
public:
    Doodlebug();
    Doodlebug(int newX = -1, int newY = -1);
    void move(Organism* grid[20][20]);
    void breed(Organism* grid[20][20]);
    void starve(Organism* grid[20][20]);

    vector<int> findAdjacentAnts(Organism* grid[20][20]);
    int getStarveCount();
};

Doodlebug::Doodlebug() {
    // totalDoodlebug += 1;
    character = 88;
    coorX = -1;
    coorY = -1;
    breedCount = 0;
    starveCount = 0;
}

Doodlebug::Doodlebug(int newX, int newY) {
    // totalDoodlebug += 1;
    character = 88;
    coorX = newX;
    coorY = newY;
    breedCount = 0;
    starveCount = 0;
}

void Doodlebug::move(Organism* grid[20][20]) {
    vector<int> ants = findAdjacentAnts(grid);

    if (ants.size() != 0) {
        int num = rand() % (ants.size()/2);
        int tempX = ants[num*2];
        int tempY = ants[num*2+1];
        Organism* temp = new Organism;
        grid[coorX][coorY] = temp;
        coorX = tempX;
        coorY = tempY;
        grid[coorX][coorY] = this;
        starveCount = 0;
        // totalAnt -= 1;
    } else {
        Organism::move(grid);
        starveCount += 1;
    }

    breedCount += 1;

    if (starveCount == 3) {
        starve(grid);
        // totalDoodlebug -= 1;
    } else if (breedCount == 8) {
        breed(grid);
        breedCount = 0;
    }
    
}

void Doodlebug::breed(Organism* grid[20][20]) {
    vector<int> cells = availableCells(grid, coorX, coorY);
    if (cells.size() != 0) {
        int num = rand() % (cells.size()/2);
        int tempX = cells[num*2];
        int tempY = cells[num*2+1];
        Doodlebug* temp = new Doodlebug(tempX, tempY);
        grid[tempX][tempY] = temp;
    }
}

void Doodlebug::starve(Organism* grid[20][20]) {
    Organism* temp = new Organism;
    grid[coorX][coorY] = temp;
}

vector<int> Doodlebug::findAdjacentAnts(Organism* grid[20][20]) {
    vector<int> ants;
    if (isAnt(grid, coorX, coorY+1) == true) {
        ants.push_back(coorX);
        ants.push_back(coorY+1);
    }
    if (isAnt(grid, coorX, coorY-1) == true) {
        ants.push_back(coorX);
        ants.push_back(coorY-1);
    }
    if (isAnt(grid, coorX+1, coorY) == true) {
        ants.push_back(coorX+1);
        ants.push_back(coorY);
    }
    if (isAnt(grid, coorX-1, coorY) == true) {
        ants.push_back(coorX-1);
        ants.push_back(coorY);
    }

    return ants;
}

int Doodlebug::getStarveCount() {
    return starveCount;
}


//--------------------------------------------------------------------------------------------------------------
// World Functions

void initialization(Organism* grid[20][20]) {
    // All empty
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Organism* temp = new Organism;
            grid[i][j] = temp; 
        }
    }

    // 5 Doodlebugs
    for (int i = 0; i < 5; i++) {
        bool invalid = true;
        while (invalid) {
            int tempX = rand() % 20;
            int tempY = rand() % 20;
            if (cellCondition(grid, tempX, tempY) == true) {
                Doodlebug* temp = new Doodlebug(tempX, tempY);
                delete grid[tempX][tempY];
                grid[tempX][tempY] = nullptr;
                grid[tempX][tempY] = temp;
                invalid = false;
            }
        }
    }

    // 100 Ants
    for (int i = 0; i < 100; i++) {
        bool invalid = true;
        while (invalid) {
            int tempX = rand() % 20;
            int tempY = rand() % 20;
            if (cellCondition(grid, tempX, tempY) == true) {
                Ant* temp = new Ant(tempX, tempY);
                grid[tempX][tempY] = temp;
                invalid = false;
            }
        }
    }
}

vector<int> availableCells(Organism* grid[20][20], int x, int y) {
    vector<int> cells;
    if (cellCondition(grid, x, y+1) == true) {
        cells.push_back(x);
        cells.push_back(y+1);
    }
    if (cellCondition(grid, x, y-1) == true) {
        cells.push_back(x);
        cells.push_back(y-1);
    }
    if (cellCondition(grid, x+1, y) == true) {
        cells.push_back(x+1);
        cells.push_back(y);
    }
    if (cellCondition(grid, x-1, y) == true) {
        cells.push_back(x-1);
        cells.push_back(y);
    }
    return cells;
}

bool cellCondition(Organism* grid[20][20], int x, int y) {
    if (x < 0 || x > 19 || y < 0 || y > 19) {
        return false;
    }
    if (grid[x][y]->getCharacter() == 45) {
        return true;
    } else {
        return false;
    }
}

bool isAnt(Organism* grid[20][20], int x, int y) {
    if (x < 0 || x > 19 || y < 0 || y > 19) {
        return false;
    }
    if (grid[x][y]->getCharacter() == 111) {
        return true;
    } else {
        return false;
    }
}

void printWorld(Organism* grid[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << char(grid[i][j]->getCharacter()) << " ";
        }
        cout << "\n";
    }
}



int main() {
    srand(time(NULL));
    Organism* grid[20][20];
    int timeStep = 0;

    initialization(grid);
    cout << "Current time step: " << timeStep << endl;
    // cout << "Ant population: " << totalAnt << endl;
    // cout << "Doodlebug population: " << totalDoodlebug << endl;
    printWorld(grid);

    string deter = "";
    while (deter != "stop") {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (grid[i][j]->getCharacter() == 88) {
                    grid[i][j]->move(grid);
                }
            }
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (grid[i][j]->getCharacter() == 111) {
                    grid[i][j]->move(grid);
                }
            }
        }
        timeStep += 1;
        cout << "Current time step: " << timeStep << endl;
        // cout << "Ant population: " << totalAnt << endl;
        // cout << "Doodlebug population: " << totalDoodlebug << endl;
        printWorld(grid);

        cout << "Press Enter to continue, type 'stop' to stop: ";
        getline(cin, deter); 

    }


}

/*

Doodlebug* d1 = new Doodlebug(19,0);
    Ant* a1 = new Ant(18, 0);

    cout << "1\n";
    initialization(grid);
    printWorld(grid);

    grid[18][0] = a1;
    grid[19][0] = d1;
    cout << "2\n";
    printWorld(grid);


    d1->move(grid);
    cout << "3\n";
    printWorld(grid);

    d1->move(grid);
    cout << "4\n";
    printWorld(grid);

    d1->move(grid);
    cout << "5\n";
    printWorld(grid);

    cout << "BreedCount: " << d1->getBreedCount() << endl;
    cout << "StarveCount: " << d1->getStarveCount() << endl;

    d1->move(grid);
    cout << "6\n";
    printWorld(grid);

*/