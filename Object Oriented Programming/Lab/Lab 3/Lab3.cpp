#include<iostream>

using namespace std;

/*
Kyle Wang
ww2301@nyu.edu
CS 2124 Lab 3
*/

bool isPalindrome(string input) {
    int p2 = input.length() - 1;
    for(int i = 0; i < input.length()/2; i++) {
        if (input[i] != input[p2]) {
            return false;
        }
        p2--;
    }
    return true;
}

// bool isPalindrome2(char* input) {
//     int length = sizeof(input)/sizeof(input[0]);
//     // cout << "Length: " << length << endl;
//     // cout << sizeof(input) << endl;
//     // cout << sizeof(input[0]) << endl;
//     int p2 = length - 1;
//     for(int i = 0; i < length/2; i++) {
//         if (input[i] != input[p2]) {
//             return false;
//         }
//         p2--;
//     }
//     return true;
// }

int main () {

    // // Task 2
    // // 42, 42
    // // 53, 53
    // // 88, 52


    // // Task 5
    // int* A;
    // A = new int(100);
    // int * B;
    // B = A;
    // cout << "The value of A is " << *A << endl;
    // cout << "A is pointing to the location " << A << endl;
    // cout << "The value of B is " << *B << endl;
    // cout << "B is pointing to the location " << B << endl;
    // cout << "Returning the memory for A to the heap: " << endl;
    // delete A;
    // cout << "The value of A is " << *A << endl;
    // cout << "A is pointing to the location " << A << endl;
    // cout << "The value of B is " << *B << endl;
    // cout << "B is pointing to the location " << B << endl;   

    // // Task 6
    // int x[5] = {0,1,4,9,16};
    // int length = sizeof(x)/sizeof(x[0]);
    // for(int i = 0; i < length; i++) {
    //     cout << x[i] << " ";
    // }
    // cout << endl;

    // // Task 7
    // int numberOfEle;
    // cout << "Enter the number of new values to create: ";
    // cin >> numberOfEle;

    // int input;
    // for(int i = 0; i < numberOfEle; i++) {
    //     cout << "Enter new value: ";
    //     cin >> input;
    //     x[i] = input;
    // }
    
    // // int y[length + numberOfEle];
    // // for(int i = 0; i < length; i++) {
    // //     y[i] = x[i];
    // // }
    // // int input;
    // // for(int i = 0; i < numberOfEle; i++) {
    // //     cout << "Enter new value: ";
    // //     cin >> input;
    // //     y[length + numberOfEle] = input;
    // //     cout << "Value added" << endl;
    // // }

    // // length = sizeof(y)/sizeof(y[0]);
    // cout << "New Array: ";
    // for(int i = 0; i < length; i++) {
    //     cout << x[i] << " ";
    // }
    // cout << endl;

    // // Task 8
    // // idk

    // // Task 9 
    // int* arr = new int[0];
    // int deter = 2;
    // int size = 0;
    // int num;
    // while (deter == 2) {
    //     cout << "Enter the value to add: ";
    //     cin >> num;
    //     arr[size++] = num;
    //     cout << "Type 1 to end loop, type 2 to continue: ";
    //     cin >> deter;
    // }

    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << endl;
    // }

    // Task 10
    // char str2[8] = "racecar";
    // bool temp = isPalindrome2(str2);
    // if (temp == true) {
    //     cout << "True" << endl;
    // } else {
    //     cout << "False" << endl;
    // }

    char str[] = "Hello";
    char* str2 = str;
    cout << sizeof(str2);


}

