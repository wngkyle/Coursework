#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class Organism;

class World {
    int gridVal[20][20];
    Organism grid[20][20];
public:
    World();
    bool cellCondition(int x, int y);
    void setCellEmpty(int x, int y);
    void setCell(int val, Organism* temp);

    void printWorld();
};

World::World() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            gridVal[i][j] = 45;
        }
    }
}

bool World::cellCondition(int x, int y) {
    if (x > 19 || y > 19) { // out of bound
        return false;
    }
    if(gridVal[x][y] == 45) {
        return true;
    } else {
        return false;
    }
}

void World::setCellEmpty(int x, int y) {
    gridVal[x][y] = 45;
    grid[x][y] = nullptr;
}

void World::setCell(int val, Organism* temp) {
    gridVal[temp->getCoorX()][temp->getCoorY()] = val;
    grid[temp->getCoorX()][temp->getCoorY()] = temp;
}

void World::printWorld() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; i < 20; j++) {
            cout << gridVal[i][j] << " ";
        }
        cout << "\n";
    }
}


class Organism {
private:
    int coorX;
    int coorY;
protected:
    World existWorld;
public:
    Organism();
    Organism(World& temp);
    Organism(World& temp, int newX, int newY);
    void move();
    vector<int> emptyCells();
    
    void setCoorX(int newX) { coorX = newX; }
    int getCoorX() { return coorX; }
    void setCoorY(int newY) { coorY = newY; }
    int getCoorY() { return coorY; }
};

Organism::Organism(World& temp) { // Remember to set cell to the organism (Solved)
    existWorld = temp;
    srand(time(0));
    bool invalid = true;
    while(invalid == true) {
        int tempX = rand() % 20;
        int tempY = rand() % 20;
        if(existWorld.cellCondition(tempX, tempY) == true) {
            coorX = tempX;
            coorY = tempY;
            invalid = false;
            // Cell on the grid is still empty not yet fully initialized (Solved)
        }
    }
}

Organism::Organism(World& temp, int newX, int newY) {
    existWorld = temp;
    coorX = newX;
    coorY = newY;
}

void Organism::move() { // Remember to set new gridVal position to "o" or "X"
    srand(time(0));
    int direction = rand() % 4 + 1;
    if(direction == 1) { // up
        if(existWorld.cellCondition(coorX, coorY+1) == true) {
            existWorld.setCellEmpty(coorX, coorY);
            coorY += 1;            
        }
    } else if(direction == 2) { // down
        if(existWorld.cellCondition(coorX, coorY-1) == true) {
            existWorld.setCellEmpty(coorX, coorY);
            coorY += 1;  
        }
    } else if(direction == 3) { // right
        if(existWorld.cellCondition(coorX+1, coorY) == true) {
            existWorld.setCellEmpty(coorX, coorY);
            coorX += 1;  
        }
    } else { // left
        if(existWorld.cellCondition(coorX-1, coorY) == true) {
            existWorld.setCellEmpty(coorX, coorY);
            coorX -= 1;  
        }
    }
}


vector<int> Organism::emptyCells() {
    vector<int> result;

    if(existWorld.cellCondition(coorX, coorY+1) == true) {
        result.push_back(coorX);
        result.push_back(coorY+1);
    } 
    if(existWorld.cellCondition(coorX, coorY-1) == true) {
        result.push_back(coorX);
        result.push_back(coorY-1);
    }
    if(existWorld.cellCondition(coorX+1, coorY) == true) {
        result.push_back(coorX+1);
        result.push_back(coorY);
    }
    if(existWorld.cellCondition(coorX-1, coorY) == true) {
        result.push_back(coorX-1);
        result.push_back(coorY);
    }

    return result;
}

class Ant : public Organism {
    int breedCount;
public:
    Ant(World& temp);
    Ant(World& temp, int newX, int newY);
    void move();
    void breed();
};

Ant::Ant(World& temp) {
    Organism(temp);
    existWorld.setCell(111, this);
    breedCount = 0;
}

Ant::Ant(World& temp, int newX, int newY) {
    Organism(temp, newX, newY);
    existWorld.setCell(111, this);
    breedCount = 0;
}

// void Ant::move() {
//     Organism::move();
//     existWorld.setCell(111, this);
//     breedCount += 1;
//     if (breedCount == 3) {
//         breed();
//         breedCount = 0;
//     }
// }

// void Ant::breed() {
//     vector<int> cellToMove = emptyCells();
//     if(cellToMove.size() > 0) {
//         srand(time(0));
//         int num = rand() % (cellToMove.size()/2);
//         int tempX = cellToMove[num*2];
//         int tempY = cellToMove[num*2+1];
//         // existWorld.setCell(111, &(Ant(existWorld, tempX, tempY)))
//         Ant(existWorld, tempX, tempY);
//     }
// } 


int main() { 
    World world1;
    Ant a1(world1);
    
}