#include <iostream>
#include <fstream>

using namespace std;

class Angle {
    int degree;
    int minute;
    int second;
public:
    Angle() : degree(0), minute(0), second(0) {}
    Angle(int degree, int minute, int second) : degree(degree), minute(minute), second(second) {}
    void getDataKB();
    void print();

    friend Angle operator+(Angle& a1, Angle& a2);
    friend Angle& operator++(Angle& a1);
    friend Angle operator++(Angle& a1, int);
    friend Angle operator-(Angle& a1, Angle& a2);
    friend bool operator==(Angle a1, Angle a2);
    friend bool operator>(Angle a1, Angle a2);
    friend bool operator<(Angle a1, Angle a2);
    friend istream& operator>>(istream& input, Angle& a1);
    friend ostream& operator<<(ostream& output, const Angle& a1);
};

void Angle::getDataKB() {
    cout << "Enter degree: ";
    int ndegree;
    cin >> ndegree;
    cout << "Enter minute: ";
    int nminute;
    cin >> nminute;
    cout << "Enter second: ";
    int nsecond;
    cin >> nsecond;
    this->degree = ndegree;
    this->minute = nminute;
    this->second = nsecond;
}

void Angle::print() {
    cout << "Degree: " << degree << endl;
    cout << "Minute: " << minute << endl;
    cout << "Second: " << second << endl;
}

Angle operator+(Angle& a1, Angle& a2) {
    int newDegree = a1.degree + a2.degree;
    int newMinute = a1.minute + a2.minute;
    int newSecond  = a1.second + a2.second;
    if(newSecond > 60) {
        newSecond -= 60;
        newMinute++;
    }
    if(newMinute > 60) {
        newMinute -= 60;
        newDegree++;
    }
    Angle temp(newDegree, newMinute, newSecond);
    temp.print();
    return temp;
}

Angle& operator++(Angle& a1) {
    a1.degree += 1;
    return a1;
}

Angle operator++(Angle& a1, int) {
    Angle temp(a1);
    temp.degree += 1;
    return temp;
}

Angle operator-(Angle& a1, Angle& a2) {
    int newDegree = a1.degree - a2.degree;
    int newMinute = a1.minute - a2.minute;
    int newSecond = a1.second - a2.second;
    if(newSecond < 0) {
        newSecond += 60;
        newMinute -= 1;
    }
    if(newMinute < 0) {
        newMinute += 60;
        newDegree -= 1;
    }
    return Angle(newDegree, newMinute, newSecond);
}

bool operator==(Angle a1, Angle a2) {
    if (a1.degree == a2.degree && a1.minute == a2.minute && a1.second == a2.second) {
        return true;
    } else {
        return false;
    }
}

bool operator>(Angle a1, Angle a2) {
    if (a1.degree > a2.degree) {
        return true;
    } else if (a1.degree < a2.degree) {
        return false;
    } else if (a1.minute > a2.minute) {
        return true;
    } else if (a1.minute < a2.minute) {
        return false;
    } else if (a1.second > a2.second) {
        return true;
    } else {
        return false;
    }
}

bool operator<(Angle a1, Angle a2) {
    return a2 > a1;
}

istream& operator>>(istream& input, Angle& a1) {
    input >> a1.degree >> a1.minute >> a1.second;
    return input;
}

ostream& operator<<(ostream& output, const Angle& a1) {
    output << a1.degree << ":" << a1.minute << ":" << a1.second;
    return output;
}

int main() {
    Angle a1(40,5,10);
    Angle a2(20,20,20);
    Angle temp;
    cin >> temp;
    temp.print();

}