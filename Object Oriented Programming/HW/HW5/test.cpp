#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int size;
    int capacity;
public:
    Stack();
    void add(int val);
    int pop();
};

Stack::Stack() {
    arr = new int[5];
    size = 0;
    capacity = 5;
}

void Stack::add(int val) {
    arr[size] = val;
    size += 1;
}

int Stack::pop() {
    int temp = arr[size-1];
    size -= 1;
    return temp;
}

int main() {
    Stack s1;
    s1.add(1);
    s1.add(2);
    s1.add(5);
    s1.add(9);
    int temp;
    temp = s1.pop();
    cout << temp << endl;
    temp = s1.pop();
    cout << temp << endl;
}