#include <iostream>
#include <vector>

using namespace std;

// Problem 1
void reverseString(char* input) {
    int length = strlen(input); // 5
    char* front = input;
    char* end = input + length - 1;
    char temp1;
    char temp2;
    for (int i = 0; i <= length/2; i++) {
        temp1 = *(front + i);
        temp2 = *(end - i);
        *(front + i) = temp2;
        *(end - i) = temp1;
    }
}


// Problem 2
void insertNewVal(int* arr, int length, int newVal) {

    int index;
    for(int i = 0; i < length; i++) {
        if(newVal < arr[i]) {
            index = i;
            break;
        }
    }

    int* newArr = new int[length+1];
    for(int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = newVal;
    for(int i = index; i < length + 1; i++) {
        newArr[i+1] = arr[i];
    }

    delete[] arr;
    arr = new int[length+1];
    
    for(int i = 0; i < length+1; i++) {
        arr[i] = newArr[i];
    }
}


// Problem 3
void studentGrade() {
    int temp;
    int index;
    vector<int> grade;
    do {
        cout << "Enter student grade (type -1 to stop): ";
        cin >> temp;

        // Sorting it into ascending order
        index = grade.size();
        for(int i = 0; i < grade.size(); i++) {
            if(temp < grade[i]) {
                index = i;
                break;
            }
        }  
        grade.insert(grade.begin() + index, temp);

    } while (temp != -1);

    int* histogram = new int[100];
    int histogramIndex = 0;
    int histogramLength = 0;
    int count = 1;

    // Building the histogram array using dynamic array on heap
    for(int i = 2; i < grade.size(); i++) {
        if(grade[i] == grade[i-1]) {
            count += 1;
        } else {
            histogram[histogramIndex++] = grade[i-1];
            histogram[histogramIndex++] = count;
            histogramLength += 2;
            count = 1;
        }
    }
    histogram[histogramIndex] = grade[grade.size()-1];
    histogramIndex += 1;
    histogram[histogramIndex] = count;
    histogramLength += 2;
    
    for(int i = 0; i < histogramLength; i += 2) {
        cout << "Number of " << histogram[i] << "'s: " << histogram[i+1] << endl;
    }
}



int main() {
    // Problem 1
    char test[] = "Bottle";
    reverseString(test);
    cout << "Reverse of 'Bottle': " << test << endl;
    
    // Problem 2
    int* arr = new int[10];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    arr[6] = 8;
    arr[7] = 9;
    arr[8] = 10;
    cout << "Before: ";
    for(int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    insertNewVal(arr, 9, 7); // Adding 7
    cout << "\nAfter: ";
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    // Problem 3
    studentGrade();
}