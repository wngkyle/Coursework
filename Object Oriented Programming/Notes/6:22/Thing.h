// #ifndef TIHNG_H
// #define THING_H

class Thing {
    int x;
public:
    Thing(int newVal);
    int getX();
    void printX();
};


Thing::Thing(int newVal) {
    x = newVal;
}

// #endif