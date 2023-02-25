#include <iostream>

using namespace std;

class myLocation {
    int xCoor;
    int yCoor;
public:
    myLocation();
    myLocation(int newX, int newY);
    void display();
};

myLocation::myLocation() {
    cout << "In the no argument constructor of myLocation" << endl;
    xCoor = 0;
    yCoor = 0;
}

myLocation::myLocation(int newX, int newY) {
    cout << "In the two arguments constructor of myLocation" << endl;
    xCoor = newX;
    yCoor = newY;
}

void myLocation::display() {
    cout << "In the display function of myLocation" << endl;
    cout << "X-coordinate: " << xCoor << endl;
    cout << "Y-coordinate: " << yCoor << endl;
}


class myPoint : public myLocation { 
protected:
    char color;
public:
    myPoint();
    myPoint(int newX, int newY, char newColor);
    void display();
};

myPoint::myPoint() {
    myLocation();
    color = 'a';
}

myPoint::myPoint(int newX, int newY, char newColor) {
    myLocation(newX, newY);
    color = newColor;
}

void myPoint::display() {
    myLocation::display();
    cout << "Color: " << color << endl;
}



int main() {
    //Option 1
    // myLocation l1;
    // myLocation l2(5, 7);
    // l1.display();
    // l2.display();

    //Option 2
    // myPoint p1;
    myPoint p2(1, 6, 'r');
    p2.display();

    //Option 3

}