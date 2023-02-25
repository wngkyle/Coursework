#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <ctime> 

using namespace std;


class Organism {
protected:
    int coorX;
    int coorY;
public:
    Organism();
    virtual void move(int gridVal[20][20], Organism grid[20][20], int val);
};

// World Methods 
vector<int> emptyCells(int gridVal[20][20], int x, int y);
bool cellCondition(int gridVal[20][20], int x, int y); // used
void setCellToEmpty(int gridVal[20][20], Organism grid[20][20], int x, int y); // used
// World Methods 

Organism::Organism() {
    coorX = -1;
    coorY = -1;
}

void Organism::move(int gridVal[20][20], Organism grid[20][20], int val) {
    int direction = rand() % 4 + 1;
    cout << "Direction: " << direction << endl;
    if(direction == 1) { // up
        if(cellCondition(gridVal, coorX, coorY+1) == true) {
            setCellToEmpty(gridVal, grid, coorX, coorY);
            coorY += 1;
            gridVal[coorX][coorY] = val;
            grid[coorX][coorY] = *this;
        }
    } else if(direction == 2) { // down
        if(cellCondition(gridVal, coorX, coorY-1) == true) {
            setCellToEmpty(gridVal, grid, coorX, coorY);
            coorY -= 1;
            gridVal[coorX][coorY] = val;
            grid[coorX][coorY] = *this;
        }
    } else if(direction == 3) { // right
        if(cellCondition(gridVal, coorX, coorY-1) == true) {
            setCellToEmpty(gridVal, grid, coorX, coorY);
            coorX += 1;
            gridVal[coorX][coorY] = val;
            grid[coorX][coorY] = *this;
        }
    } else { // left
        if(cellCondition(gridVal, coorX, coorY-1) == true) {
            setCellToEmpty(gridVal, grid, coorX, coorY);
            coorX -= 1;
            gridVal[coorX][coorY] = val;
            grid[coorX][coorY] = *this;
        }
    }
}

class Ant : public Organism {
    int breedCount;
public:
    Ant();
    Ant(int x, int y);
    void setXY(int x, int y);
    void move(int gridVal[20][20], Organism grid[20][20]);
    void breed(int gridVal[20][20], Organism grid[20][20]);

    void printAntInfo() { cout << "X: " << coorX << " Y: " << coorY << endl; } 

};

Ant::Ant() {
    Organism();
    breedCount = 0;
}

Ant::Ant(int x, int y) {
    coorX = x;
    coorY = y;
    breedCount = 0;
}

void Ant::setXY(int x, int y) {
    coorX = x;
    coorY = y;
}

void Ant::move(int gridVal[20][20], Organism grid[20][20]) {
    Organism::move(gridVal, grid, 111);
    breedCount += 1;
    if(breedCount == 3) {
        breed(gridVal, grid);
        breedCount = 0;
    }
}

void Ant::breed(int gridVal[20][20], Organism grid[20][20]) {
    vector<int> availableCells = emptyCells(gridVal, coorX, coorY);
    if (availableCells.size() != 0) {
        int num = rand() % (availableCells.size()/2);
        int tempX = availableCells[num*2];
        int tempY = availableCells[num*2+1];
        gridVal[tempX][tempY] = 111;
        grid[tempX][tempY] = Ant(tempX, tempY);
    }
}

// World Methods

vector<int> initializeWorld(int gridVal[20][20], Organism grid[20][20], vector<Organism*> allOrganism) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            gridVal[i][j] = 45;
            grid[i][j] = Organism();
        }
    }
    vector<int> result;
    // Testing : Initializing 5 ants
    for(int i = 0; i < 5; i++) {
        bool invalid = true;
        while(invalid) {
            int tempX = rand() % 20;
            int tempY = rand() % 20;
            if(gridVal[tempX][tempY] == 45) {
                result.push_back(tempX);
                result.push_back(tempY);
                gridVal[tempX][tempY] = 111;
                grid[tempX][tempY] = Ant(tempX, tempY);
                allOrganism.push_back(&(grid[tempX][tempY]));
                invalid = false;
            }
        }
    }
    return result;
}

vector<int> emptyCells(int gridVal[20][20], int x, int y) {
    vector<int> result;

    if(gridVal[x][y+1] == 45) { // up
        result.push_back(x);
        result.push_back(y+1);
    }
    if(gridVal[x][y-1] == 45) { // down
        result.push_back(x);
        result.push_back(y-1);
    }
    if(gridVal[x+1][y] == 45) { // right
        result.push_back(x+1);
        result.push_back(y);
    }
    if(gridVal[x-1][y] == 45) { // left
        result.push_back(x-1);
        result.push_back(y);
    }

    return result;
}

bool cellCondition(int gridVal[20][20], int x, int y) {
    if(x > 19 || y > 19) { // out of bound
        return false;
    }
    if(gridVal[x][y] == 45) {
        return true;
    } else {
        return false;
    }
}

void setCellToEmpty(int gridVal[20][20], Organism grid[20][20], int x, int y) {
    gridVal[x][y] = 45;
    Organism tmp;
    grid[x][y] = tmp;
}

void printWorld(int gridVal[20][20]) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cout << char(gridVal[i][j]) << " ";
        }
        cout << "\n";
    }
}



/*
Problems:
    - Should the array/vector storing organism(Ant & Doodlebug) be pointers or actual objects?


*/

int main() {
    srand(time(NULL));
    int gridVal[20][20]; // Printed World
    Organism grid[20][20]; // Actual World

    vector<Organism*> allOrganism; // Storing the pointers


    Ant a1(12,13);

    vector<int> testCoor = initializeWorld(gridVal, grid, allOrganism);

    for(int i = 0; i < allOrganism.size(); i++) {
        cout << "here";
        allOrganism[i]->getXY();
    }

    cout << "\n";

    for(int i = 0; i < testCoor.size(); i += 2) {
        cout << testCoor[i] << testCoor[i+1] << endl;
    }

    printWorld(gridVal);
    




}

/*
gridVal[12][13] = 111;
grid[12][13] = a1;

cout << "Time 1" << endl;
printWorld(gridVal);

a1.move(gridVal, grid);
cout << "Time 2" << endl;
printWorld(gridVal);

a1.move(gridVal, grid);
cout << "Time 3" << endl;
printWorld(gridVal);

a1.move(gridVal, grid);
cout << "Time 4" << endl;
printWorld(gridVal);
*/