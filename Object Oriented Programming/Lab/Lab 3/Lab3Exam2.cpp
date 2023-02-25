#include <iostream> 

using namespace std; 

int findLowestIndex(int* arr, int len, int startPos) {
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

int findLowestVal(int* arr, int len, int startPos) {
    int minVal = arr[startPos];
    int minIndex = startPos;
    for(int i = startPos; i < len; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
    return minVal;
}


int* sort(int* arr, int length) {
    int newArr[length];
    for(int i = 0; i < length; i++) {
        int min = findLowestVal()
    }
}

int main() {
    int arr[] = {2,1,5,7,2,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int* newArr = sort(arr, len);

    for(int i = 0; i < 6; i++) {
        cout << newArr[i] << endl;
    }

}