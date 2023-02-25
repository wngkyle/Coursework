#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Part One
string isInVector(vector<int> y, int num) {
    for(int i = 0; i < y.size(); i++) {
        if (num == y[i]) {
            return to_string(num) + " is in the vector";
        }
    }
    return to_string(num) + " is not in the vector";
}

// Part Two
void makeUnique(vector<int> input, vector<int>& output) {
    for(int i = 0; i < input.size(); i++) {
        bool deter = true;
        for(int j = 0; j < output.size(); j++) {
            if (input[i] == output[j]) {
                deter = false;
                break;
            }
        }
        if (deter == true) {
            output.push_back(input[i]);
        }
    }
}

// Part Three
void fillVectorFromFile(vector<int>& output) {
    string fileName;
    cout << "Enter File Name: ";
    cin >> fileName;
    fstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) {
        //cout << "Fail to open file" << endl;
    } else {
        //cout << "File opened" << endl;
        int temp;
        while(outFile >> temp) {
            output.push_back(temp);
            //cout << temp << endl;
        }
    }
}

// Part Four
void writingIntoNewFile() {
    string fileName;
    cout << "Enter File Name: ";
    cin >> fileName;
    fstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) {
        cout << "Fail to open file" << endl;
    } else {
        cout << "File opened" << endl;
        ofstream myFile("uniq.ints.txt");
        int temp;
        vector<int> input;
        vector<int> output;
        while(outFile >> temp) {
            input.push_back(temp);
        }
        makeUnique(input, output);
        for(int i = 0; i < output.size(); i++) {
            myFile << output[i] << endl;
        }
    }
}


int main() {
    // Part One
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);
    x.push_back(8);
    x.push_back(9);
    string result = isInVector(x, 4);

    // Part Two
    vector<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(8);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    y.push_back(9);
    y.push_back(6);
    y.push_back(7);
    y.push_back(8);
    y.push_back(9);
    vector<int> z; // Empty vector
    makeUnique(y, z);
    // cout << "size of y : " << y.size() << endl;
    // cout << "size of z : " << z.size() << endl;

    // Part Three
    vector<int> a;
    fillVectorFromFile(a);

    // Part Four
    writingIntoNewFile();



}