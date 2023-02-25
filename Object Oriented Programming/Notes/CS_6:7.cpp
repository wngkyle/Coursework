#include <iostream>

using namespace std;

// Complie time
// Load time
// Run time

class IndexOutOfBounds {};
class DynArray {
    private: 
        int currentCapacity; // Maximum number of items we could store
        int currentSize; // Number of items we are storing
        int* data; // pointer to our data array
        void resize(int newCapacity); // Theta(N)
    public:
        DynArray();
        void push_back(int value); // Amortized theta(1)
        int pop_back(); // Theta(1)
        int size() const {return currentSize;} // Constant-fying the object, not changing any private instance variable // Theta(1)
        int capacity() const {return currentCapacity;} // Theta(1)
        int getAt(int position) const; // Theta(1)
        void setAt(int position, int value); // Theta(1), fails if position is greater than currentCapacity
        void clear(); // Theta(1)
        bool is_empty() const {return currentSize == 0;}
};

DynArray::DynArray() {
    currentCapacity = 5;
    currentSize = 0;
    data = new int[currentCapacity];
}

void DynArray::resize(int newCapacity) {
    int* temp = new int[newCapacity];
    int copyLimit;
    if (newCapacity <= currentSize) {
        copyLimit = newCapacity;
        currentSize = newCapacity;
    } else {
        copyLimit = currentSize;
    }
    for (int i = 0; i < copyLimit; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    currentCapacity = newCapacity;
}

void DynArray::push_back(int value) {
    if (currentSize == currentCapacity) {
        resize(currentCapacity * 2);
    }
    data[currentSize++] = value; // Store the value first, and then increment currentSize by 1
}

int DynArray::pop_back() {
    if (currentSize == 0) {
        throw IndexOutOfBounds(); // create new IndexOutOfBounds object and throw it to indicate a problem
    }
    return data[--currentSize];

    /*
    int temp = data[currentSize -1];
    currentSize -= 1;
    return temp;
    */
}

int DynArray::getAt(int position) const {
    if (position >= currentSize || position < 0) {
        throw IndexOutOfBounds();
    }
    return data[position];
}

void DynArray::setAt(int position, int value) {
    if (position >= currentCapacity || position < 0) {
        throw IndexOutOfBounds();
    } else if (position >= currentSize) {
        push_back(value);
        return;
    }
    data[position] = value;
}

void DynArray::clear() {
    delete[] data;
    currentCapacity = 5;
    currentSize = 0;
    data = new int[currentCapacity];
}




// void swap(int& a, int& b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void swap(string& a, string& b) {
//     string temp = a;
//     a = b;
//     b = temp;
// }
template <class T> // could also be template <typename T> ; T could be anything you like 
// T can be anything, name it whatever you like
void swap(T& a, T& b) {
    T temp = a; 
    a = b;
    b = temp;
}

template <class T> 
class Thing {
    public:
        Thing(T newVal = T()); // I don't know what a new value should be for this, so I will use default
        // If there's no default contructor for the thing you want to store, then you can't
        T x;
};
// This is how vector works, how they are able to store different object types
template <class T> 
Thing<T>::Thing(T newVal) {
    x = newVal;
}


int main() {
    DynArray d1;
    for (int i = 0; i < 100; i++) {
        d1.push_back(i * 10);
    }
    for (int i = 0; i < d1.size(); i++) {
        cout << d1.getAt(i) << endl;
    }
    cout << "***********************************" << endl;
    while(!d1.is_empty()) {
        cout << d1.pop_back() << endl;
    }
    
    
    
    
    // int size = 100;
    // cout << "What size?";
    // cin >> size;
    // // int arr[size]; // Stack-dynamic array, size must be known at complile time
    // const int CONST_SIZE = 100;
    // int arr[CONST_SIZE];
    // int* dyarr = new int[size]; // Heap-dynamic array, size can be dynamic
}