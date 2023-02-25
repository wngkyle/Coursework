/*


T operator[](int index) const { return data[index]; } // If the array is constantify (const array), this line will be called. By only returning value, user cannot change the value
T& operator[](int index) { return data[index]; } // If the array is normal array, this line will be called. By returning the reference, users can change the value 

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Measurement; // Pre-definition of measurement to allow for parameter in Demo

class Demo {
public: 
    void changeMeasurement(Measurement& m);
};

class Measurement {
    int feet;
    int inches;
    void normalize();
public:
    Measurement(int totalInches = 0) : inches(totalInches) { normalize(); }
    int getInches() const { return inches; }
    int getFeet() const { return feet; }
    void setFeet(int newFeet) { feet = newFeet; }
    void setInches(int newInches);
    int getTotalInches() const { return feet * 12 + inches; }
    Measurement operator+(const Measurement& rhs) const;
    Measurement& operator-=(const Measurement& rhs);
    Measurement& operator++(); // Post-increment
    Measurement operator++(int); // pre-increment operator (due to int)

    friend istream& operator>>(istream& ins, Measurement& rhs); // Not a member 
    friend class Demo; // All of those member functions have access to our private stuff
};

void Demo::changeMeasurement(Measurement& m) { m.inches++; }


// cout is type o stream
// cin is type i stream
ostream& operator<<(ostream& outs, const Measurement& rhs) { // return type is void??? (book)
    outs << rhs.getFeet() << "\' " << rhs.getInches() << "\"";
    return outs;
}

// return type is not void for << and >> is b/c you can't use the operator continuously

istream& operator>>(istream& ins, Measurement& rhs) { // Still a non-member operator, but can make it a friend of the measurement class
    ins >> rhs.feet >> rhs.inches;
    return ins;
}

bool operator < (const Measurement& lhs, const Measurement& rhs) {    
    return lhs.getTotalInches() < rhs.getTotalInches(); 
}

bool operator > (const Measurement& lhs, const Measurement& rhs) {    
    return rhs.getTotalInches() < lhs.getTotalInches();    
}

bool operator <= (const Measurement& lhs, const Measurement& rhs) {    
    return !(rhs < lhs);    
}

bool operator >= (const Measurement& lhs, const Measurement& rhs) {    
    return !(lhs < rhs);    
}

bool operator == (const Measurement& lhs, const Measurement& rhs) {    // fill in from class notes 
    return !(lhs < rhs || rhs < lhs);    
}

bool operator != (const Measurement& lhs, const Measurement& rhs)  {    // fill in from class notes
    return lhs < rhs || rhs < lhs;    
}

Measurement& Measurement::operator++() { // Post-increment
    inches++;
    normalize();
    return *this;
}

Measurement Measurement::operator++(int) { // Pre-increment
    Measurement temp(*this); // copy this object first
    inches++;
    normalize();
    return temp;
}

// Operator of non-member of the class need two parameter values, they need two pass in values

Measurement operator-(const Measurement& lhs, const Measurement& rhs) { 
    return Measurement(lhs.getTotalInches() - rhs.getTotalInches());
}

// Operator of member of the class automatically has one operand, the object calling the function.
// Therefore, they only need one parameter value

Measurement& Measurement::operator-=(const Measurement& rhs) {
    feet -= rhs.feet;
    inches -= rhs.inches;
    normalize();
    return *this;
}

// When returning, if the thing is created by the function return by value, if the thing exist already outside the function
// and is manipulated inside the function return by reference

Measurement Measurement::operator+(const Measurement& rhs) const {
    Measurement temp;
    temp.inches = getTotalInches() + rhs.getTotalInches();
    temp.normalize();
    return temp;
}

void Measurement::setInches(int newInches) {
    inches = newInches;
    normalize();
}

void Measurement::normalize() {
    if (inches >= 12) {
        feet += inches/12;
        inches %= 12;
    } 
    while (inches < 0) {
        feet--;
        inches += 12;
    }
}

//----------------------------------------------------------------------------------------------

class Person {
    string name;
    Person* spouse;
public:
    Person(string newName = "") : name(newName), spouse(nullptr) {}
    string getName() const { return name; }
    void setName(string newName) { name = newName; }
    bool isMarried() const { return spouse != nullptr; }
    bool marry(Person& other);
    string getSpouseName() const { return isMarried() ? spouse->name : "NOT MARRIED"; }
};

bool Person::marry(Person& other) {
    if (isMarried() || other.isMarried()) {
        return false;
    }
    spouse = &other;
    other.spouse = this; // "this" is a pointer to the calling object (myself)
    return true;
}

//----------------------------------------------------------------------------------------------

void func1(int var) {
    cout << "inside func1" << endl;
    var = 100;
}

void func2(int& var) { // not var, but reference to x
    cout << "insides func2" << endl;
    var = 100;
}

void func3(int* var) {
    cout << "inside func3" << endl;
    *var = 150;
    // var = new int(200); // incidental memory leak
    // impossible to access var after function ends
}

void func4(int* var) {
    cout << "inside func4" << endl;
    *var = 200;
}

void func5(int*& var) {
    cout << "inside func5" << endl;
    var = new int(250);
}

int main() {
    

}

