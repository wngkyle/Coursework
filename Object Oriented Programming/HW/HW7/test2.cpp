#include <iostream>

using namespace std;

// class big {
// protected:
//     int x;  
// public:
//     big();
//     big(int newX);
//     virtual int getValue() {return x;}
// };

// big::big() {
//     x = 5;
//     cout << "Big constructor" << endl;
// }

// big::big(int newX) {
//     x = newX;
//     cout << "Big constructor" << endl;
// }

// class small : public big {
//     int y;
// public:
//     small();
//     small(int newNum);
//     int getValue() {return x;}
// };

// small::small() {
//     big();
//     y = 9;
//     cout << "Default Small constructor" << endl;
// }

// small::small(int newNum) {
//     big(newNum);
//     y = 9;
//     cout << "Small constructor" << endl;
// }




int main() {
    int* x = new int[5];
    int* y = new int(1);
    x[2] = 9;

}