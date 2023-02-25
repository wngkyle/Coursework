#include <iostream>
#include <stdio.h>      
#include <stdlib.h>   
#include <time.h>

using namespace std;

class Vehicle {
    int* id;
    double* mileage;
public:
    Vehicle();
    Vehicle(int newID, double newMileage);
    void setID(int newID);
    int getID() const;
    void setMileage(double newMileage);
    double getMileage() const;
    void display();
    virtual double calcGasUsed(double mileDriven);
    void drive();
};

Vehicle::Vehicle() {
    id = new int(0);
    mileage = new double(0.0);
}

Vehicle::Vehicle(int newID, double newMileage) {
    id = new int(newID);
    mileage = new double(newMileage);
}

void Vehicle::setID(int newID) {
    delete id;
    id = new int(newID);
}

int Vehicle::getID() const {
    return *id;
}

void Vehicle::setMileage(double newMileage) {
    delete mileage;
    mileage = new double(newMileage);
}

double Vehicle::getMileage() const {
    return *mileage;
}

void Vehicle::display() {
    cout << "ID: " << *id << endl;
    cout << "Mileage: " << *mileage << endl;
}

double Vehicle::calcGasUsed(double mileDriven) {
    double result = mileDriven / (*mileage);
    return result;
}

void Vehicle::drive() {
    srand(time(NULL));
    double randNum = rand() % 25 + 1;
    double result = calcGasUsed(randNum);
    cout << "Miles driven: " << randNum << " miles" << endl;
    cout << "Gas Used: " << result << " gallons" << endl;
}


class SUV : public Vehicle {
    bool* fourWDStatus;
    double* fourWDGasMileage;
public:
    SUV();
    SUV(int newID, double newMileage, bool val1, double val2);
    void setFourWDStatus(bool newVal);
    bool getFourWDStatus() const;
    void setFourWDGasMileage(double newVal);
    double getFourWDGasMileage() const;
    void display();
    double calcGasUsed(double mileDriven);
};

SUV::SUV() {
    Vehicle();
    fourWDStatus = new bool(false);
    fourWDGasMileage = new double(0.0);
}

SUV::SUV(int newID, double newMileage, bool val1, double val2) {
    // Vehicle(newID, newMileage);
    this->setID(newID);
    this->setMileage(newMileage);
    fourWDStatus = new bool(val1);
    fourWDGasMileage = new double(val2);
}

void SUV::setFourWDStatus(bool newVal) {
    delete fourWDStatus;
    fourWDStatus = new bool(newVal);
}

bool SUV::getFourWDStatus() const {
    return *fourWDStatus;
}

void SUV::setFourWDGasMileage(double newVal) {
    delete fourWDGasMileage;
    fourWDGasMileage = new double(newVal);
}

double SUV::getFourWDGasMileage() const {
    return *fourWDGasMileage;
}

void SUV::display() {
    Vehicle::display();
    cout << "fourWDStatus: " << *fourWDStatus << endl;
    cout << "fourWDGasMileage: " << *fourWDGasMileage << endl;
}

double SUV::calcGasUsed(double mileDriven) {
    // cout << "here" << endl;
    if((*fourWDStatus) == false) {
        // cout << "if" << endl;
        double result = Vehicle::calcGasUsed(mileDriven);
        return result;
    } else {
        // cout << "else" << endl;
        double result = mileDriven / (*fourWDGasMileage);
        return result;
    }
}



int main() {
    Vehicle v1(1213, 20);
    SUV s1(1125, 25, false, 30);
    SUV s2(3244, 32, true, 40);

    Vehicle car[] = {v1, s1, s2};

    cout << "Vehicle 1: " << endl;
    car[0].drive();

    cout << "\nSUV 1: " << endl;
    car[1].drive();

    cout << "\nSUV 2: (Four wheel mode)" << endl;
    car[2].drive();


}







// void SUV::drive() {
//     srand(time(NULL));
//     double randNum = rand() % 25 + 1;
//     double result = calcGasUsed(randNum);
//     cout << "Miles driven: " << randNum << " miles" << endl;
//     cout << "Gas Used: " << result << " gallons" << endl;
// }