#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Person{
    private:
        string name;
        string gender;
        int age;
    public:
        Person(string x, string y, int z);
        void setName(string x);
        string getName();
        void setGender(string x);
        string getGender();
        void setAge(int x);
        int getAge();
};

Person::Person(string x, string y, int z) {
    name = x;
    gender = y;
    age = z;
}

void Person::setName(string x) {
    name = x;
}

string Person::getName() {
    return name;
}

void Person::setGender(string x) {
    gender = x;
}

string Person::getGender() {
    return gender;
}

void Person::setAge(int x) {
    age = x;
}

int Person::getAge() {
    return age;
}

void fillVectorFromFile(vector<int>& output) {
    string fileName;
    cout << "Enter File Name: ";
    cin >> fileName;
    fstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) {
        cout << "Fail to open file" << endl;
    } else {
        cout << "File opened" << endl;
        string temp;
        int actualNum;
        while(outFile) {
            temp = outFile.get();
            actualNum = stoi(temp);
            output.push_back(actualNum);
            cout << actualNum << endl;
        }
    }
}

void func() {
    string fileName;
    cout << "Enter File Name: ";
    cin >> fileName;
    fstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) {
        cout << "Fail to open file" << endl;
    } else {
        cout << "File opened" << endl;
        int actualNum;
        while(outFile >> actualNum) {
            cout << actualNum << endl;
        }
    }
}

void func2() {
    string filename("testFile.txt");
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }

    while (input_file >> number) {
        cout << number << endl;
    }
    cout << endl;
    input_file.close();

}

void func3() {
    string filename("testFile.txt");

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    } else {
        for(int i = 0; i < 3; i++) {
            char myFile = input_file.get();
            cout << myFile << endl;
        }
    }
    cout << endl;
    input_file.close();

}










int main() {
   Person p1("Kyle", "Male", 19);
   cout << p1.getName();
}
