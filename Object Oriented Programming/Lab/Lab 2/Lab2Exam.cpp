#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

class Data {
    private:
    double gas;
    double odometer;
    int efficiencyRating;
    public:
    Data(double newGas = 15, double newOdometer = 0, int newEfficiencyRating = 25) {
        gas = newGas;
        odometer = newOdometer;
        efficiencyRating = newEfficiencyRating;
    }
    void setGas(int newGas){
        gas = newGas;
    }
    int getGas() {
        return gas;
    }
    void setEfficiency(int efficiency) {
        efficiencyRating = efficiency;
    }
    int getEfficiency() {
        return efficiencyRating;
    }
};


class Car : public Data{
    private:
    string make;
    string model;
    int licenseNum;
    Data data();
    public:
    Car(string newMake = "(unspecified)", string newModel = "(unspecified)", int newLicenseNum = NULL, int efficiency = 25) {
        make = newMake;
        model = newModel;
        licenseNum = newLicenseNum;
        setEfficiency(efficiency);
    }
    void setLicense(int newLicense) {
        licenseNum = newLicense;
    }
    int getLicense() {
        return licenseNum;
    }
    void refillGas() {
        setGas(15);
    }
    int drive() {
        srand (time_t(NULL));
        double randNum = rand() % 25 + 1;
        int milesDriven = randNum / getEfficiency();
        int temp = getGas();
        if (milesDriven < temp) {
            int result = temp - milesDriven;
            setGas(result);
            return result;
        } else {
            cout << "Drive is not executed because gas will go below zero" << endl;
            return temp;
        }
    
    }
};


int main() {
    Car c1;
    Car c2("makeCB");
    Car c3("make1", "model1", 123);
    Car c4("make2", "(unspecified)", 456, 20);
    
    c2.setLicense(1010);
    
    int temp = c1.drive();
    cout << temp << endl;


}
