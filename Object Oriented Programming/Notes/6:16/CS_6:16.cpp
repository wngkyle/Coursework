#include <iostream>
#include <vector>

using namespace std;

class HeapMem {
    int* data;
public:
    HeapMem(int newval = 0) : data(new int(newval)) {}
	HeapMem(const HeapMem& rhs); // Copy-constructor
	HeapMem(HeapMem&& rhs); // Move constructor
    ~HeapMem(); // Destructor
    int getVal() const { return *data; }
    void setVal(int newval) { *data = newval; }
    HeapMem& operator=(const HeapMem& rhs); // Assignment operator
	HeapMem& operator=(HeapMem&& rhs); // Move operator
};
// Move constructor and operator shift the data from one to another instead of copying the data over
// This makes it more efficient and save memory


HeapMem::HeapMem(const HeapMem& rhs) { //Copy constructor
	data = new int(*rhs.data);
	cout << "Copy-constructing a HeapMem object" << endl;

	
	// data = nullptr;
	// *this = rhs; // calling operator=
}

HeapMem::HeapMem(HeapMem&& rhs) { // Move constructor (for copy constructor)
	data = rhs.data;
	rhs.data = nullptr;
}


// This is called automatically by the program itself when it detects object falling out of scope
// No need to set data to nullptr b/c this is a destructor, and data won't even exist after the funtion ends
HeapMem::~HeapMem() { // Destruct HeapMem object that falls out of the scope
    delete data;
    cout << "Destructing a HeapMem object" << endl;
}

// This prevent double deletion by making sure initialization is on different references
HeapMem& HeapMem::operator=(const HeapMem& rhs) {
    if (this != &rhs) { // test for self-assignment, m1 = m1, if it's self-assignment then do nothing
        delete data;
        data = new int(*rhs.data);
    }
    return *this;
}


// Assignment operator leaves two copies, the original and duplicate, after the function ends
// Move operator destroy one copy, the original, leaving the duplicate after the function ends
HeapMem& HeapMem::operator=(HeapMem&& rhs) { // Move operator
    if (this != &rhs) { 
        data = rhs.data;
		rhs.data = nullptr;
    }
	return *this;
}


void func() {
	HeapMem m1;
    cout << "Constructing a HeapMem object" << endl;
}

void demo1() { 
    HeapMem m1(100);
    HeapMem m2(200);
    m1 = m2;
}

int main() {

    

    // HeapMem m1(10);
    // HeapMem m2 = 20;
    // HeapMem m3;
    // HeapMem m4(m1); // this uses a different constructor then the above initializations, the copy-constructor, construct while duplicating 
	// HeapMem m5 = m1; // same thing as the one above

    // m3 = m2;

    // func();

    demo1(); // Cause double deletion 
    // B/c m1 and m2 are referenced to the same place, which is 200, so when m1 is deleted by the destructor, there is nothing left for m2 to delete


}