#include <iostream>
#include <vector>
#include <list>

using namespace std;

double sumArray(int* arr, int size) { // arr is an Array
    if(size == 0) {
        return 0;
    } 
    double smaller = sumArray(arr, size - 1);
    double retval = smaller + arr[size-1];
    return retval;
}

// Uses pointers instead of size 
double sumArray2(int* arr, int size) { // arr is an Array
    if(size == 0) {
        return 0;
    } 
    double smaller = sumArray(arr+1, size - 1);
    double retval = smaller + (*arr);
    return retval;
}

double power(int base, int exp) {
    if(exp == 0) {
        return 1;
    } else if(exp > 0) {
        return power(base, exp-1) * base;
    } else { // exp < 0
        return 1 / power(base, -exp);
    }
}

void countUp(int n) {
    // static int i = 0; 
    // Static
    // This cause the variable to exist in the memory forever
    // If i is 2 in the first call and will increment by 1 every call, i will be 4 in the third call
    if (n <= 0) {
        return;
    }
    countUp(n-1); // Reduction of the set by single case
    cout << n << endl; // Single  case
    
}

void countDown(int n) {
    if (n <= 0) {
        return;
    }
    cout << n << endl; // Single  case
    countDown(n-1); // Reduction of the set by single case
}

void printAB(int n) {
    if(n <= 0) {
        return;
    }
    cout << "A";
    printAB(n - 1);
    cout << "B";
}

bool isPalindrome(const char* str, int size) {
    if(size == 0) 
        return true;
    if(str[0] > 'Z' || str[0] < 'A')
        return isPalindrome(str + 1, size - 1);
    else if(str[size - 1] > 'Z' || str[size - 1] < 'A')
        return isPalindrome(str, size - 1);
    else if(str[0] != str[size - 1]) 
        return false;
    return isPalindrome(str + 1, size - 2); // size - 2 b/c both the first and the last element are removed
}

void printList(const list<int>& l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); i++) { // The iterator must be const b/c the list is passed in as consitfied
    // If the iterator is not consitfied, it will be potentially allow the user to change the value, in which the program will not work and will result in error
        cout << *i << endl;
    }
}

int main() {
    // countUp(5);

    // int* arr = new int[3];
    // arr[0] = 5;
    // arr[1] = 2;
    // arr[2] = 3;
    // cout << sumArray2(arr, 3);
    // delete[] arr;
    // arr = nullptr;


    // printAB(3); // Output: AAABBB


    // const char* str = "RACECAR"; // Pointer can change, characters cannot
    // // char const* cptr;
    // char* const cptr; // Characters can change, pointers cannot
    // char* cptr2; // Characters and pointer can change
    // const char* const cptr3; // Characters cannot change, pointer cannot change
    // if(isPalindrome(str, strlen(str))) {
    //     cout << "Is a palindrome" << endl;
    // } else {
    //     cout << "Is not a palindrome" << endl;
    // }

    // const char* cstr = "A MAN, A PLAN, A CANAL, PANAMA!";
    // if(isPalindrome(cstr, strlen(cstr))) {
    //     cout << "Is a palindrome" << endl;
    // } else {
    //     cout << "Is not a palindrome" << endl;
    // }


    // list<int> l;
    // for (int i = 0; i < 10; i++) {
    //     l.push_back(i*10);
    // }

    // for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
    //     cout << *i << endl;
    // }

    // // Goes from the end to the beginning
    // // In reverse order
    // for (list<int>::reverse_iterator i = l.rbegin(); i != l.rend(); i++) {
    //     cout << *i << endl;
    // }



}