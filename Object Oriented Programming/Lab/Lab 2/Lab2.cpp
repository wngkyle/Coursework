#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DeliveryTruck {
    private:
        string ad;
        int thePackages[50];
        int index;
    
    public:
        DeliveryTruck(string advert = ""){
            ad = advert;
            index = 0;
        }
        void setAd(string advert);
        void readFile();
};

void DeliveryTruck :: setAd(string advert) {
    ad = advert;
    cout << "Current advertisement on the truck: " << ad << endl;
}

void DeliveryTruck :: readFile() {
    fstream outFile;
    string fileName;
    string line;
    double val;
    cout << "Enter File Name: ";
    getline(cin, fileName);
    outFile.open(fileName);
    while(outFile >> line){
        if (!(line.find(".") == string::npos)) {
            val = stod(line);
            thePackages[index] = val;
            index = index + 1;
            cout << val << endl;
        }
        
    }
}

int main() {
    // string userInput;
    // do {
    //     cout << "Menu:\n" << "1. Default Delivery Truck\n" << "Option 2\n" << "Option 3\n" << "Option 4\n" << "Enter your choice: ";
    //     getline(cin, userInput);
    //     cout << "Your choice is " << userInput << endl;
    // } 
    // while (userInput.empty());

    DeliveryTruck truck1;
    truck1.setAd("new advertisement");
    truck1.readFile();
}