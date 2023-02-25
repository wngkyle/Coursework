#include <iostream>

using namespace std;


//find index of lowest
int findLowest(int* arr, int len, int startPos) {
    int minVal = arr[startPos];
    int minIndex = startPos;
    for(int i = startPos; i < len; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}


int* sort(int* arr, int length) {
    int* newArr = new int[100];
    for(int i = 0; i < length; i++) {
        int indexOfLowest = findLowest(arr, length, i);
        newArr[i] = arr[indexOfLowest];
        int temp = arr[i];
        arr[i] = arr[indexOfLowest];
        arr[indexOfLowest] = temp;
    }
    return newArr;
}


void print(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int* arr = new int[100];
    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 9;
    arr[4] = 17;
    arr[5] = 3;
    arr[6] = 7;

    int temp = findLowest(arr, 7, 2);
    cout << temp;

    int* temp = sort(arr, 7);
    
    cout << "newArr: " << endl;
    for(int i = 0; i < 7; i++) {
         cout << temp[i] << endl;
    }

    cout << "arr: " << endl;
    for(int i = 0; i < 7; i++) {
         cout << arr[i] << endl;
    }

    // cout << arr[4] << endl;
}