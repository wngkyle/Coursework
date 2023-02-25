#include <iostream>

using namespace std;

void func() {
    int* ptr = new int(10);
}

int* func2() {
    int* x = new int(100);
    return x;
}

void func3(int* ptr) {
    delete ptr;
}

class Thing {
    public:
        int x;
};

class ThingWithPtr {
    public:
        int* x;
};

int main() {
    Thing one;
    one.x = 100;
    Thing* thingPtr = new Thing;
    (*thingPtr).x = 100; // Star operator has lower precedence than the dot operator in the order of operation
    cout << "(*thingPtr).x : " << (*thingPtr).x << endl;
    thingPtr->x = 100; // Same as (*thingPtr).x = 100;
    cout << "thingPtr->x : " << (*thingPtr).x << endl;
    // Whatever is to the left of -> must be a pointer
    ThingWithPtr tmp;
    //tmp = new int(100); // Incorrect b/c tmp is a ThingWithPtr object
    tmp.x = new int(100); // Correct b/c tmp.x is a pointer
    cout << "*tmp.x : " << *tmp.x << endl; // No need of -> b/c in this case, we want the dot operation to go first and THEN the star operation

    delete thingPtr;

    ThingWithPtr* tmpPtr = new ThingWithPtr;
    tmpPtr->x = new int(200);
    delete tmpPtr->x;
    delete tmpPtr;

    // //--------------------------------------------------------------------------------------------------------------------

    for(int i = 0; i < 100; i++) { 
        func(); // Memory waste
    }

    for(int i = 0; i < 100; i++) {
        int* ptr = func2(); // Create and then delete
        func3(ptr);
    }

    // //--------------------------------------------------------------------------------------------------------------------

    int capacity = 100;
    int* arr = new int[capacity]; // An array of 100 integers on the heap
    arr[0] = 100;
    cout << "Address of arr: " << arr << endl;
    cout << "Value of arr[0] / *arr: " << *arr << endl; // Prints 100
    int* second = (arr + 1); // Pointer arithmetic, c++ worries about the size of an int
    *second = 200;
    cout << "Address of second / (arr + 1): " << second << endl;
    cout << "Value of arr[1] / *second: " << arr[1] << endl;

    //--------------------------------------------------------------------------------------------------------------------

    int* ptr = new int(10);
    int* otherptr = ptr;
    cout << "Ptr: " << ptr << endl;
    cout << "Otherptr: " << otherptr << endl;
    delete ptr;
    // delete otherptr; // double deletion, otherptr and ptr have the same memory 
    cout << "-------Deleted ptr--------" << endl;
    cout << "ptr: " << ptr << endl;
    cout << "otherptr: " << otherptr << endl; // Dangling pointer, potentially hazardous to the system
    cout << "ptr's value: " << *ptr << endl;
    cout << "otherptr's value: " << *otherptr << endl;
    ptr = otherptr = nullptr; // Could also be NULL; potects the system
    cout << "-------Set to NULL--------" << endl;
    cout << "ptr: " << ptr << endl;
    cout << "otherptr: " << otherptr << endl;
    // if (otherptr != nullptr) 
    //     cout << "otherptr's value: " << *otherptr << endl; // You cannot dereference NULL 
    cout << "Finished Successfully" << endl;

    //--------------------------------------------------------------------------------------------------------------------

    int x = 5;
    cout << x << endl; //5
    cout << "Address of x: " << &x << endl; //prints out the address of x
    int* ptr = &x; // Address of x
    cout << "Address of x by printing ptr: " << ptr << endl; // Address of x
    cout << "Address of ptr: " << &ptr << endl; // Address of ptr
    int** intPtrPtr = &ptr; // pointer to a integer pointer (use double**)
    cout << "Address of ptr by printing intPtrPtr: " << intPtrPtr << endl; // Address of intPtrPtr

    // Dereferencing variables
    // * - dereference
    cout << "Dereferene ptr: " << *ptr << endl;
    cout << "Dereference intPtrPtr: " << **intPtrPtr << endl;
    cout << "X: " << x << endl;

    // //--------------------------------------------------------------------------------------------------------------------

    // Create variables on heap with keyword 'new' 
    // Destroy variables on heap with keywork 'delete'
    int* ptr = new int; // A new variable is created on the heap and referenced by ptr
    // int* ptr = new int; ?????
    *ptr = 10;
    cout << *ptr << endl;
    delete ptr; // Prevents garbage on the heap (Memory leak)
    ptr = new int;
    *ptr = 7;
    cout << "Address of the int before deletion (ptr): " << ptr << endl;
    cout << "Value of the int before deletion (*ptr): " << *ptr << endl;
    delete ptr; // Deleting the variable
    cout << "Address of the int after deletion (ptr): " << ptr << endl;
    cout << "Value of the int after deletion (*ptr): " << *ptr << endl; // Even though the variable is deleted, it will still link to some number. This is the protective mechanism in the system.

    // Note:
    // Delete command only free the memory in use by that pointer. So it will only release the value 6 not the int type.
    //
    // According to stack overflow....
    //
    // int* ptr = new int(6); reserves some memory where ptr will be pointing to, that memory will be good to store one int, 6 or any other, 
    // it cannot be used to do anything else, you can reliably store the data there and access it later. After you delete it you tell the 
    // system that the memory is available and the program can use it for whatever else it wants. ptr may still be pointing to the same 
    // address(the value of the pointer) and you can still print it, but that memory no longer belongs to ptr, accessing that memory 
    // through it (e.g.: dereferencing the pointer), amounts to undefined behavior.
    // 
    // or
    // 
    // delete ptr releases the memory that ptr points at (which was created as new int (6)). It doesn't change the value of that pointer. 
    // So cout << ptr will print the same value (of the pointer) as it did before doing delete ptr. If you were to print *ptr after having 
    // done delete ptr the behaviour is undefined (which means it COULD print the value 6, it COULD print "garbage", but the result COULD
    // also be reformatting your hard drive - undefined behaviour means any outcome is possible).

}