#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pet { //abstract because of speak
	string name;
public:
	Pet(string newname = "") :name(newname) {}
	string getName() const { return name; }
	virtual void changeName(string newname) { name = newname; speak(); }
	//eat
	virtual void speak()const = 0; //note the absence of {}; pure virtual function
};

class Dog : public Pet {
	int usualWalkingTime;
public:
	Dog(string newname, int newusualWalkingTime = 240) : 
		usualWalkingTime(newusualWalkingTime), Pet(newname) {}
	int getUsualWalkingTime() const { return usualWalkingTime; }
	void changeTime(int newtime) { usualWalkingTime = newtime; }
	void changeName(string newname, int newusualWalkingTime);
	virtual void changeName(string newname); //Override
	Dog& operator=(const Pet&); // allows dog=pet, otherwise it will be an error!
	virtual void speak() const { cout << "WOOF WOOF!" << endl; }
};
class Cat : public Pet {
	int sleepingTime;
public:
	Cat(string name, int newsleepingtime = 1200) : sleepingTime(newsleepingtime), Pet(name) {}
	int getSleepingTime() const { return sleepingTime; }
	void changeTime(int newtime) { sleepingTime = newtime; }
	virtual void changeName(string newname); //Override
	virtual void speak() const { cout << "Meow Meow!" << endl; }
};
void Cat::changeName(string newname) {
	sleepingTime = 1200;
	Pet::changeName(newname);
}

Dog& Dog::operator=(const Pet& p) {
	//changeName(p.getName());
	usualWalkingTime = 240;
	Pet::operator=(p); //same as *this=p but with the base class operator=
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
	HeapMemInt *test=new HeapMemTwo;
	delete test;
	test = nullptr;
}
int main() {
	vector<Pet*> v;
	v.push_back(new Cat("Fluffy"));
	v.push_back(new Dog("Fido"));
	v.push_back(new Cat("Whiskers"));

	for (int i = 0; i < v.size(); i++)
		v[i]->speak();

/*	for (int i = 0; i < 1000000000; i++)
		testFunc();
*/	/*
	Pet p1;
	Dog fido("fido");
	Dog fluffy("fluffy");

	Pet* pptr;
	Dog* dptr;
	dptr = &fido;
	pptr = &fido;
	//dptr = &p1; //this can NEVER be done!
	dptr->changeTime(1080);
	pptr->changeName("Fluffy"); //works properly if changeName is virtual!
	cout << fido << endl;
	*/
	/*fluffy.changeTime(1080);

	cout << p1<<fido << fluffy << endl;
	fido = fluffy;
	cout << "Assigned fluffy to fido..." << endl;
	cout << p1<<fido << fluffy << endl;

	p1 = fido;
	cout << "Assigned fido to p1..." << endl;
	cout << p1 << fido << fluffy << endl;

	p1.changeName("Maybe a dog");
	fido = p1;
	cout << "Assigned p1 to fido..." << endl;
	cout << p1 << fido << fluffy << endl;
	*/

}