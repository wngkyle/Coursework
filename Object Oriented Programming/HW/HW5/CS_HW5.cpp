#include <iostream>

using namespace std;

class Time {
    int day;
    int hour;
    int minute;
public:
    Time(int newDay = 0, int newHour = 0, int newMinute = 0);
    void normalize(int totalTime);
    void setDay(int newDay);
    int getDay () const;
    void setHour(int newHour);
    int getHour() const;
    void setMinute(int newMinute);
    int getMinute() const;
    void print(); // For testing
    Time& operator++(); // Pre-Increment (Assign later)
    Time operator++(int); // Post-Increment (Assign first)
    Time& operator--(); // Pre-Increment
    Time operator--(int); // Post-Increment 

    friend Time operator+(Time& t1, Time& t2);
    friend Time operator-(Time& t1, Time& t2);
    friend ostream& operator<<(ostream& output, Time& t1);
};

Time::Time(int newDay, int newHour, int newMinute) {
    int totalTime = newDay * 24 * 60 + newHour * 60 + newMinute;
    normalize(totalTime);
}

void Time::normalize(int totalTime) {
    if (totalTime > 0) {
        minute = totalTime % 60;
        totalTime -= minute;
        totalTime /= 60;
        hour = totalTime % 24;
        day = totalTime / 24;
    } else {
        minute = totalTime % 60;
        totalTime -= minute;
        totalTime /= 60;
        hour = totalTime % 24;
        day = totalTime / 24;
        if(minute == 0) {
            hour = 24 + hour;
            day -= 1;
        } else {
            minute += 60;
            hour += 23;
            day -= 1;
        }
        if (hour == 24) {
            hour = 0;
            day += 1;
        }
    }
}

void Time::setDay(int newDay) {
    day = newDay;
}

int Time::getDay () const {
    return day;
}

void Time::setHour(int newHour) {
    if (newHour == 24) {
        hour = 0;
        day += 1;
    } else {
        hour = newHour;
    }
}

int Time::getHour() const {
    return hour;
}

void Time::setMinute(int newMinute) {
    minute = newMinute;
    int totalTime = day * 24 * 60 + hour * 60 + minute;
    normalize(totalTime);
}

int Time::getMinute() const {
    return minute;
}

void Time::print() {
    cout << "Day: " << day << endl;
    cout << "Hour: " << hour << endl;
    cout << "Minute: " << minute << endl;
}

Time operator+(Time& t1, Time& t2) {
    int totalTime1 = t1.day * 24 * 60 + t1.hour * 60 + t1.minute;
    int totalTime2 = t2.day * 24 * 60 + t2.hour * 60 + t2.minute;
    int sum = totalTime1 + totalTime2;
    Time temp;
    temp.normalize(sum);
    return temp;
}

Time operator-(Time& t1, Time& t2) {
    int totalTime1 = t1.day * 24 * 60 + t1.hour * 60 + t1.minute;
    int totalTime2 = t2.day * 24 * 60 + t2.hour * 60 + t2.minute;
    int sum = totalTime1 - totalTime2;
    Time temp;
    temp.normalize(sum);
    return temp;
}

ostream& operator<<(ostream& output, Time& t1) {
    if (t1.minute < 10) {
        output << t1.hour << ":0" << t1.minute << " (" << t1.day << ")";
    } else {
        output << t1.hour << ":" << t1.minute << " (" << t1.day << ")";
    }
    return output;
}

Time& Time::operator++() { // Pre-Increment
    minute += 1;
    int totalTime = day * 24 * 60 + hour * 60 + minute;
    normalize(totalTime);
    return *this;
}

Time Time::operator++(int) { // Post-Increment
    Time temp(*this);
    minute += 1;
    int totalTime = day * 24 * 60 + hour * 60 + minute;
    normalize(totalTime);
    return temp;
}

Time& Time::operator--() { // Pre-Drecrement
    minute -= 1;
    int totalTime = day * 24 * 60 + hour * 60 + minute;
    normalize(totalTime);
    return *this;
}

Time Time::operator--(int) { // Post-Decrement
    Time temp(*this);
    minute -= 1;
    int totalTime = day * 24 * 60 + hour * 60 + minute;
    normalize(totalTime);
    return temp;
}

int main() {
    Time t1(4,23,45);
    Time t2(-7,3,20);
    Time t3 = t1 + t2;
    Time t4 = t1--;
    cout << t1 << endl; // Change
    cout << t4 << endl; // Doesn't Change
}