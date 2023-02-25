#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class Organism;
class World;


class Organism {
    World existWorld;
    int coorX;
    int coorY;
public:
    Organism() : coorX(0), coorY(0) {}
    Organism(World& temp);
    void setXY(int newX, int newY);

    void move();
};

Organism::Organism(World& temp) {
    existWorld = temp;
    coorX = 0;
    coorY = 0;
}

void Organism::setXY(int newX, int newY) {
    coorX = newX;
    coorY = newY;
}






class World {
    int gridVal[20][20];
    Organism grid[20][20];
    vector<Organism*> ants;
    vector<Organism*> doodlebugs;

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
    srand(time(0));
    for(int i = 0; i < 5; i++) {
        bool invalid = true;
        while(invalid == true) {
            int tempX = rand() % 20;
            int tempY = rand() % 20;
            if(cellCondition(tempX, tempY) == true) {
                gridVal[tempX][tempY] = 79;
                grid[tempX][tempY] = Organism(*this); 
                grid[tempX][tempY].setXY(tempX, tempY);
                
                /* 
                Change organism to 5 doodlebugs and 100 ants
                Remember to push back each organism to the respective vector
                */
                invalid = false;
            }
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

void World::printWorld() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cout << char(gridVal[i][j]) << " ";
        }
        cout << "\n";
    }
}    


int main() {
    World w1;
    w1.printWorld();
}