#include <iostream>

using namespace std;

// Classes can be based on other classes to create an "is-a" siutation
// During inheritance, the existing class, called a base class, is enlarged to form a derived class
// Everything (functions and data) in the base class will exist in the derived class
// Derived class can create new versions of existing functions, which is called overriding
// Inheritance does not change private access, the dervied class cannot access private

// Protected should be a rarity, you should not use this often


class Pet { // Abstract Class b/c of speak
    string name;
public:
    Pet(string newname = " ") : name(newname) {}
    string getName() const { return name; }
    virtual void changeName(string newname) { name = newname; } // Virtual keyword
    // eat
    // speak
    virtual void speak() const = 0; // note the absence of {} ; pure virtual function
    // Class that contain pure virtual functions are abstract class, and you can never create an object of an abstract class
    // Pointers of abstract class are allowed 
};

class Dog : public Pet {
    int usualWalkingTime;
public:
    Dog(string newname, int newusualWalkingTime = 240) : usualWalkingTime(newusualWalkingTime), Pet(newname) {}
    int getUsualWalkingTime() const { return usualWalkingTime; }
    void changeTime(int newTime) { usualWalkingTime = newTime; }
    void changeName(string newname, int newusualWalkingTime);
    void changeName(string newname); // Override
    Dog& operator=(const Pet&); // Allows dog = pet, otherwise it will be an error!
    virtual void speak() const { cout << "Woaf! Woaf!" << endl; }
};

Dog& Dog::operator=(const Pet& p) {
    // changeName(p.getName());
    usualWalkingTime = 240;
    Pet::operator=(p); // same as *this=p but with the base class operator=
    // Above copies the pet portion of the data
    return *this;
}

void Dog::changeName(string newname) {
    usualWalkingTime = 240;
    Pet::changeName(newname);
}

void Dog::changeName(string newname, int newusualWalkingTime) {
    usualWalkingTime = newusualWalkingTime;
    Pet::changeName(newname);
}

ostream& operator<<(ostream& outs, const Dog& d) {
    outs << "Name: " << d.getName() << "\tTime: " << d.getUsualWalkingTime() << endl;
    return outs;
}

ostream& operator<<(ostream& outs, const Pet& d) {
    outs << "Name: " << d.getName() << endl;
    return outs;
}

class Cat : public Pet {
	int sleepingTime;
public:
	Cat(string name, int newsleepingtime = 1200) : sleepingTime(newsleepingtime), Pet(name) {}
	int getSleepingTime() const { return sleepingTime; }
	void changeTime(int newtime) { sleepingTime = newtime; }
	virtual void changeName(string newname); //Override
	virtual void speak() const { cout << "Meow Meow!" << endl; }
};


class HeapMemInt {
	int* i;
public:
	HeapMemInt(int newi = 0) :i(new int(newi)) {}
	HeapMemInt(const HeapMemInt& rhs) :i(new int(*rhs.i)) {}
	HeapMemInt& operator=(const HeapMemInt& rhs) { *i = *rhs.i; return *this; }
	virtual ~HeapMemInt() { delete i; }
};

class HeapMemTwo :public HeapMemInt{
public:
	double* d;
	HeapMemTwo(int newi = 0, double newd = 0) :HeapMemInt(newi), d(new double(newd)) {}
	HeapMemTwo(const HeapMemTwo& rhs) :d(new double(*rhs.d)), HeapMemInt(rhs) {}
	HeapMemTwo& operator=(const HeapMemTwo& rhs);
	virtual ~HeapMemTwo() { delete d; d = nullptr; }
};

HeapMemTwo& HeapMemTwo::operator=(const HeapMemTwo& rhs) {
	*d = *rhs.d;
	HeapMemInt::operator=(rhs);
	return *this;
}


void testFunc() {
    HeapMemInt *test = new HeapMemTwo;
    delete test;
    test = nullptr;

    // This cause memory leak
    // B/c when delete is called, since test is HeapMemInt type pointer, the destructor in HeapMemInt class is called, 
    // deleting the HeapMemInt part of the data in test. But the HeapMemTwo part of the data in test still exist because 
    // it was assigned to a HeapMemTwo object, and it's the destructor in HeapMemInt that was called
}


int main() {
    // for(int i = 0; i < 10000; i++) { // This cause memory leak
    //     testFunc();
    // }

    // Pet p1;
    // Dog fido("fido");
    // Dog fluffy("fluffy");
    // fluffy.changeTime(1080);

    // cout << p1 << fido << fluffy << endl;
    // fido = fluffy; // set everything equal
    // cout << "Assigned fluffy to fido....." << endl;
    // cout << p1 << fido << fluffy << endl;

    // p1 = fido; // C++ only copies the parts in dog object that will fit in the pet object
    // // In this case, only name of fido is copied over because p1 has no space to store walkingTime
    // // This mechanism is called slicing, which slice only the data that fits and copy over the object
    // cout << "Assigned fido to p1....." << endl;
    // cout << p1 << fido << fluffy << endl;

    // p1.changeName("Maybe a dog");
    // fido = p1; 
    // cout << "Assigned p1 to fido......" << endl;
    // cout << p1 << fido << fluffy << endl;


    // Pet* pptr;
    // Dog* dptr;
    // dptr = &fido;
    // pptr = &fido; 
    // // dptr = &p1; // This can NEVER be done!
    // // Base class pointer can always point to a derived class object
    // // A pet pointer can point to a dog, because derived class contains everything in the base class
    // // Base class pointer pointing toward a derived class object only have access to things in the base class

    // //However....

    // // When a overriden function is called, c++ always decide which function to called base on the data type, which is static binding
    // // Dynamic binding / late binding / Polymorphism : using a base class pointer to call an overriden function in the derived class
    // // This can be achieve by using the keyword virtual in the pet class
    // // Then in runtime, c++ decide which overriden function of the object should it call


    // dptr->changeTime(1080);
    // pptr->changeName("Fluffy"); // with virtuall added in the pet class, c++ calls the changeName function in dog class instead of pet class
    // cout << fido << endl;



}