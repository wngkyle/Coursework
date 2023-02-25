#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime> 
#include <vector>

using namespace std;

class big;
class small;

// class map {
//     big grid[5][5];
// public:
//     map();
// };

// map::map() {
//     grid[0][0] = big();
// }

class big {
    int x;  
public:
    big() : x(5) {}
    virtual int getValue() {return x;}
    virtual void printInfo() {}
};

class small : public big {
    int y;
public:
    small() : y(9) {}
    int getValue() {return y;}
    void printInfo() {cout << "Y: " << y << endl;}
};

void initialization(big* arr[5], vector<big*>& testVec) {
    small* temp = new small();
    arr[0] = temp;
    testVec.push_back(temp);
    // cout << "Inside the function: " << temp->getValue() << endl;
}

void initialization2(vector<big>& testVec) {
    // small* temp = new small();
    small s;
    testVec.push_back(s);
    cout << "Inside the function: " << s.getValue() << endl;
}

void initializaton3(big* arr[5]) {
    small* temp = new small;
    arr[0] = temp;
    big* temp1 = new big;
    arr[1] = temp1;
}

void printInfo(big* arr[5]) {
    cout << arr[0]->getValue() << endl;
    cout << arr[1]->getValue() << endl;
}

int main() {
    big* arr[5];
    // vector<big*> testVec;

    // cout << arr[0]->getValue() << endl;

    // initialization(arr, testVec);

    // cout << arr[0]->getValue() << endl;

    // cout << testVec[0]->getValue() << endl;

    // testVec[0]->printInfo();


    // big* ptr = new big();
    // small s;
    // ptr = &s;

    // cout << ptr->getValue();

    // vector<big> test;
    // initialization2(test);

    // cout << test[0].getValue();

    // arr[0][0] = nullptr;

    // if(arr[0][0] == nullptr) {
    //     cout << "NULL";
    // } else {
    //     cout << "NONE";
    // }

    srand(time(NULL));
    int x = rand() % 0;
    cout << x << endl;

    // initializaton3(arr);
    // cout << arr[0]->getValue() << endl;
    // cout << arr[1]->getValue() << endl;
    // printInfo(arr);
    
}