#include <iostream>
// #include "Thing.h"

using namespace std;

// "Student" is a "Person"
// Inheritance
// Sub-class & super-class
// Base-class & derived-class
// Child-class & parent-class

class Base {
private:
    int baseThing; // Private
protected: // Allows derived class to access but, otherwise, acts like private
    int thingWhichDerivedCanAccess; // Acts as private variable outside the class, private in derived class
public:
    Base(int newthing = 0) : baseThing(newthing) {}
    int geThing() const { return baseThing; }
    void setThing(int newthing) { baseThing = newthing; }
};

// Order of constructor : Base -> Composition -> Derived
// Destructors go in complete opposite direction

// Base constructor is never inherited
// Derived cannot call/invoke constructor of grandparents class, they can only invoke constructors of direct parent

// Access is not changed through inheritance
// Private variables are still private
// Child class has no access to private variables in parent class

class Derived : public Base { // Derived from Base class, where things are copied into the Derived class
private: 
    double deriveThing; // Private
public:
    Derived(double newVal = 0) : Base(100), deriveThing(newVal) { thingWhichDerivedCanAccess = 10;}  // Invoking base constructor
    Derived(int baseVal, double doubleVal) : Base(baseVal), deriveThing(doubleVal) {}
    void setDeriveThing(double newthing) { deriveThing = newthing; }
    double getDeriveThing() const { return deriveThing; }
    void setBoth(int newInt, double newDouble);
    void setThing(int newInt); // Override 
    void setThing(int newInt, double newDouble); // Not an override, this didn't exist in base
};

void Derived::setBoth(int newInt, double newDouble) {
    deriveThing = newDouble;
    // baseThing = newInt; // baseThing is private, have no access to it from Derived class
    setThing(newInt);
}

// Base object still called the older version or base's version of the setThing() function
void Derived::setThing(int newInt) {
    deriveThing -= 1;
    // setThing(newInt); // this will cause infinite recursion, the function is calling itself
    Base::setThing(newInt); // call to base's version of setThing()
    // The scope operator solve the problem

}




int main() {
    Derived d1;
    d1.setThing(100);
    cout << d1.getDeriveThing() << " " << d1.getDeriveThing() << endl;

    Base b1(10);
    b1.setThing(100);
    d1.setThing(200);

    
}