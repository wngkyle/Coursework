#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int size;
    int capacity;
public:
    Stack();
    Stack(Stack& s1); // Copy constructor
    ~Stack(); // Deconstructor
    Stack& operator=(Stack& s1); // Assignment operator
    void resize();
    void push(int val);
    int pop();
    int top();
    void clear();
    bool is_empty();
    
}

Stack::Stack() {
    arr = new int[5];
    size = 0;
    capacity = 5;
}

Stack::Stack(Stack& s1) { // Copy constructor
    arr = s1.arr;
}

Stack::~Stack() { // Deconstructor
    delete[] arr;
}

Stack& Stack::operator=(Stack& s1) { // Assignment operator
    delete[] arr;
    arr = new int[s1.capacity];
    capacity = s1.capacity;
    size = s1.size;
    for(int i = 0; i < size; i++) {
        arr[i] = s1.arr[i];
    }
    return *this;
}

void Stack::resize() {
    int newCapacity = capacity * 2;
    int* temp = new int[newCapacity];
    for(int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    arr = temp;
}

void Stack::push(int val) {
    if (size == capacity) {
        resize();
    }
    arr[size] = val;
    size += 1;
}

int Stack::pop() {
    int temp = arr[size - 1];
    arr[size - 1] = 0;
    size -= 1;
    return temp;
}

int Stack::top() {
    return arr[size-1];
}

void Stack::clear() {
    delete[] arr;
    arr = new int[5];
    size = 0;
    capacity = 5;
}

bool Stack::is_empty() {
    if(size == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {

}