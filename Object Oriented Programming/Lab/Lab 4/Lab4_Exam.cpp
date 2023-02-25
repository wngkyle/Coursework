#include <iostream>

using namespace std;

class Measurement {
    private:
        int inches;
        int feet;
        // void normalize1();
    public:
        Measurement(int totalInches = 0) : inches(totalInches), feet(0) { normalize(); }
        int getInches();
        int getFeet();
        void print();
        void normalize();
        int getTotalInches() const { return feet * 12 + inches; }

        Measurement operator+(Measurement& m1);
        Measurement operator-(Measurement& m1);
        Measurement& operator++(); // Post-increment
        Measurement operator++(int); // pre-increment operator (due to int)
        friend bool operator==(Measurement m1, Measurement m2);
        friend bool operator!=(Measurement m1, Measurement m2);
        friend ostream& operator<<(ostream& output, const Measurement& m1);
    };

Measurement Measurement::operator+(Measurement& m1) {
    Measurement temp;
    temp.inches = getTotalInches() + m1.getTotalInches();
    temp.normalize();
    return temp;
}

Measurement Measurement::operator-(Measurement& m1) {
    Measurement temp;
    temp.inches = getTotalInches() - m1.getTotalInches();
    temp.normalize();
    return temp;
}

Measurement& Measurement::operator++() { // Post-increment
    inches++;
    normalize();
    return *this;
}

Measurement Measurement::operator++(int) { // Pre-increment
    Measurement temp(*this); 
    inches++;
    normalize();
    return temp;
}

bool operator==(Measurement m1, Measurement m2) {
    int m1Inches = m1.getTotalInches();
    int m2Inches = m2.getTotalInches();
    if(m1Inches == m2Inches) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(Measurement m1, Measurement m2) {
    if(!(m1 == m2)) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& output, const Measurement& m1) {
    output << m1.feet << "'" << m1.inches << "''" << endl;
    return output;
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



// Measurement::Measurement(int newInches) {
//     if (newInches < 0) {
//         int numFeet = newInches / 12;
//         int numInches = newInches % 12;
//         if (numInches == 0) {
//             inches = 0;
//             feet = numFeet;
//         } else {
//             feet = numFeet - 1;
//             inches = numInches + 12;
//         }
//     } else if (newInches > 12) {
//         int numFeet = newInches / 12;
//         int numInches = newInches % 12;
//         feet = numFeet;
//         inches = numInches;
//     }
// }

void Measurement::print() {
    cout << feet << "'" << inches << "''" << endl;
}

int Measurement::getInches() {
    return inches;
}

int Measurement::getFeet() {
    return feet;
}


int main(){
    Measurement m1;
    Measurement m2(24);
    Measurement m3(-12);
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1++: " << m1++;
    cout << "m1: " << m1;
    cout << "++m1: " << ++m1;
    cout << "m1: " << m1;
    
    
    cout << endl;
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1 + m2: " << (m1 + m2);
    cout << "m2 + m3: " << (m2 + m3);
    cout << "m2 - m1: " << (m2 - m1);
    cout << "m1 - m2: " << (m1 - m2);
    
    cout << endl;
    
    cout << "m1 == m2: " << boolalpha << (m1 == m2) << endl;
    cout << "m1 != m2: " << boolalpha << (m1 != m2)<< endl;
    
    cout << endl;
    
    cout << "m2 == m2: " << boolalpha << (m2 == m2) << endl;
    cout << "m2 != m2: " << boolalpha << (m2 != m2) << endl;
}
