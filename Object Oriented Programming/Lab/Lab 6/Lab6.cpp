#include <iostream>

using namespace std;

template <class T>
class Fridge {
    T* food;
    int size;
    int capacity;
public:
    Fridge(int newSize = 17);
    ~Fridge();
    void resize(int newCapacity);
    void addFood(T foodName);
    void deleteFood(T foodName);
    bool operator<(T f2);
    // Index operator

    friend ostream& operator<<(ostream& output, T f1);
};

template <class T>
Fridge<T>::Fridge(int newSize) {
    food = new T[newSize];
    size = 0;
    capacity = newSize;
}

template <class T>
Fridge<T>::~Fridge() {
    delete[] food;
}


template <class T>
void Fridge<T>::resize(int newCapacity) {
    newCapacity *= 2;
    T* temp = new T[newCapacity];
    for(int i = 0; i < capacity; i++) {
        temp[i] = food[i];
    }
    delete[] food;
    food = temp;
    capacity = newCapacity;
}

template <class T>
void Fridge<T>::addFood(T foodName) {
    if (size == capacity) {
        resize(capacity);
    }
    food[size] = foodName;
    size += 1;
}

template <class T>
void Fridge<T>::deleteFood(T foodName) {
    int index;
    for(int i = 0; i < size; i++) {
        if(food[i] == foodName) {
            index = i;
            break;
        }
    }
    for(int i = index; i < size-1; i++) {
        food[i] = food[i+1];
    }
    food[size-1] = nullptr;
    size -= 1;
}

template <class T>
ostream& operator<<(ostream& output, T f1) {
    output << f1;
    return output;
}

template <class T>
bool Fridge<T>::operator<(T f2) {
    if(size < f2.size) {
        return true;
    } else {
        return false;
    }
}


int main() {
    Fridge<string> f1(20);

}