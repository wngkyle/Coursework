#include <iostream>
#include <vector>

using namespace std;

class StringSet {
    vector<string> data;
public:
    StringSet(vector<string>& input);
    void add(string input);
    void remove(string input);
    void clear();
    int size();

    StringSet operator+(const StringSet& rhs);
    StringSet operator*(const StringSet& rhs);
    friend ostream& operator<<(ostream& out, StringSet s1);
};

ostream& operator<<(ostream& out, StringSet s1) {
    for(int i = 0; i < s1.size(); i++) {
        out << s1.data[i] << "\n";
    }
    return out;
}

StringSet::StringSet(vector<string>& input) {
    data = input;
}

void StringSet::add(string input) {
    data.push_back(input);
}

void StringSet::remove(string input) {
    for(int i = 0; i < data.size(); i++) {
        if(data[i] == input) {
            data.erase(data.begin()+i);
            break;
        }
    }
}

void StringSet::clear() {
    data.clear();
}

int StringSet::size() {
    return data.size();
}

StringSet StringSet::operator+(const StringSet& rhs) {
    vector<string> sum;
    for(int i = 0; i < data.size(); i++) {
        sum.push_back(data[i]);
    }
    for(int i = 0; i < rhs.data.size(); i++) {
        sum.push_back(rhs.data[i]);
    }
    StringSet temp(sum);
    return temp;
}

StringSet StringSet::operator*(const StringSet& rhs) {
    vector<string> word;
    vector<int> count;

    word.push_back(data[0]);
    count.push_back(1);
    bool deter = false;
    int pos;

    // Checking this->data
    for(int i = 1; i < data.size(); i++) {
        deter = false;
        for(int index = 0; index < word.size(); index++) {
            if(data[i] == word[index]) {
                deter = true;
                pos = index;
                break;
            }
        }
        if(deter == true) {
            count[pos] += 1;
        } else {
            word.push_back(data[i]);
            count.push_back(1);
        }
    }

    // Checking rhs.data 
    for(int i = 0; i < rhs.data.size(); i++) {
        deter = false;
        for(int index = 0; index < word.size(); index++) {
            if(rhs.data[i] == word[index]) {
                deter = true;
                pos = index;
                break;
            }
        }
        if(deter == true) {
            count[pos] += 1;
        } else {
            word.push_back(rhs.data[i]);
            count.push_back(1);
        }
    }

    vector<string> result;

    for(int i = 0; i < count.size(); i++) {
        if(count[i] > 1) {
            result.push_back(word[i]);
        }
    }

    StringSet tempSet(result);

    return tempSet;
}




int main() {
    vector<string> x;
    vector<string> y;

    StringSet s1(x);
    StringSet s2(y);

    s1.add("string");
    s1.add("hi");
    s1.add("car");
    s1.add("scan");
    s1.add("hello");
    s1.add("hola");

    s2.add("bye");
    s2.add("hi");
    s2.add("string");
    s2.add("hello");
    s2.add("scan");
    s2.add("sit");

    cout << "Size: " << endl;
    cout << s1.size() << endl;

    cout << "\nOperator +: " << endl;
    cout << s1 + s2;

    StringSet s3(y);
    s3 = s1 * s2;
    cout << "\nOperator *: " << endl;
    cout << s3;

    cout << "\nRemove: " << endl;
    s3.remove("hi");
    cout << s3;

    cout << "\nClear: " << endl;
    s3.clear();
    cout << s3;
}