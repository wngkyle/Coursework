#include <iostream>

using namespace std;

int main() {
    int* x = new int(10);
    int* y = x;
    delete y;
    delete x;
}