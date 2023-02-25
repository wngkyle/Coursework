//DISPLAY 11.3 Money ClassVersion 1
//Program to demonstrate the class Money.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money {
public:
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with the
    //dollars and cents given by the arguments. If the amount is negative,
    //then both dollars and cents must be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money();
    //Initializes the object so its value represents $0.00.

    double getValue( );
    //Precondition: The calling object has been given a value.
    //Returns the amount of money recorded in the data of the calling object.

    void input(istream& ins);
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file. An amount of money, including a dollar sign, has been
    //entered in the input stream ins. Notation for negative amounts is -$100.00.
    //Postcondition: The value of the calling object has been set to
    //the amount of money read from the input stream ins.
    
    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
    //Postcondition: A dollar sign and the amount of money recorded
    //in the calling object have been sent to the output stream outs.

    friend Money add(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns the sum of the values of amount1 and amount2.

    friend bool equal(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if the amount1 and amount2 have the same value;
    //otherwise, returns false.




private:
    long allCents;
};

int digitToInt(char c);
//Function declaration for function used in the definition of Money::input:
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digitToInt('3') returns 3.


Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) { //If one is negative and one is positive 
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars*100 + cents;
}

Money::Money(long dollars) : allCents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money() : allCents(0)
{
    //Body intentionally blank.
}

double Money::getValue( )
{
    return (allCents * 0.01);
}

//Uses iostream, cctype, cstdlib:
void Money::input(istream& ins)
{
    char oneChar, decimalPoint,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    cout << digit1 << " " << digit2 << endl;

    if ( oneChar != '$' || decimalPoint != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digit1)*10 + digitToInt(digit2);

    allCents = dollars*100 + cents;
    if (negative)
        allCents = -allCents;
}

//Uses cstdlib and iostream:
void Money::output(ostream& outs)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if (allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0') );
}

Money add(Money amount1, Money amount2)
{
    Money temp;

    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

bool equal(Money amount1, Money amount2)
{
    return (amount1.allCents == amount2.allCents);
}

// void test(istream& ins) {
//     char oneChar, decimalPoint;
//     long dollar, digit;

//     ins >> oneChar >> dollar >> decimalPoint >> digit;

//     cout << "onechar: " << oneChar << endl;
//     cout << "dollar: " << dollar << endl;
//     cout << "decimal point: " << decimalPoint << endl;
//     cout << "digit: " << digit << endl;
// }

//-------------------------------------------------------------------------------------------------------------

class Check {
    int number;
    Money amount;
    bool cashed;
public: 
    Check(int checkNum, long dollar, int cent, bool condition);
    int getCheckNum();
    void setCheckNum(int newCheckNum);
    double getCheckAmount();
    void setCheckAmount(long dollar, int cent);
    bool getCheckCondition();
    void setCheckCondition(bool newCondition);
    void input(istream& ins);
    void output(ostream& outs);
    void printCheckInfo();
};

Check::Check(int checkNum, long dollar, int cent, bool condition) {
    number = checkNum;
    amount = Money(dollar, cent);
    cashed = condition;
}

int Check::getCheckNum() {
    return number;
}

void Check::setCheckNum(int newCheckNum) {
    number = newCheckNum;
}

double Check::getCheckAmount() {
    double temp = amount.getValue();
    return temp;
}

void Check::setCheckAmount(long dollar, int cent) {
    Money temp(dollar, cent);
    (*this).amount = temp; // this->amount = temp;
}

bool Check::getCheckCondition() {
    return cashed;
}

void Check::setCheckCondition(bool newCondition) {
    cashed = newCondition;
}

void Check::input(istream& ins) {
    string chkNum, chkAmount, chkCondition;
    // Retrieving and setting check number
    getline(ins, chkNum);
    if (chkNum.find("Check number:") == -1) {
        cout << "Incorrect Formatt";
        exit(1);
    }
    chkNum = chkNum.substr(chkNum.find(":")+2);
    number = stoi(chkNum); // converting string to integer

    // Retrieving and setting check amount
    getline(ins, chkAmount);
    if (chkAmount.find("Check amount:") == -1) {
        cout << "Incorrect Formatt";
        exit(1);
    }
    chkAmount = chkAmount.substr(chkAmount.find(":")+3);
    long dollar = stol(chkAmount.substr(0, chkAmount.find("."))); // converting string to long 
    int cent = stoi(chkAmount.substr(chkAmount.find(".")+1)); // converting string to integer
    setCheckAmount(dollar, cent);

    // Retrieving and setting check condition
    getline(ins, chkCondition);
    if (chkCondition.find("Check condition:") == -1) {
        cout << "Incorrect Formatt";
        exit(1);
    }
    chkCondition = chkCondition.substr(chkCondition.find(":")+2);
    if (chkCondition.compare("cashed") == 0) {
        cashed = true;
    } else {
        cashed = false;
    }
}

void Check::output(ostream& outs) {
    outs << "Check number: " << number << endl;
    outs << "Check amount: ";
    amount.output(outs);
    outs << endl << "Check condition: ";
    if (cashed == true) {
        outs << "Cashed";
    } else {
        outs << "Not Cashed";
    }
}

void Check::printCheckInfo() {
    cout << "Check number: " << number << endl;
    cout << "Check amount: " << amount.getValue() << endl;
    if (cashed == true) {
        cout << "Check condition: " << "cashed" << endl;
    } else {
        cout << "Check condition: " << "not cashed" << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------

class Account {
    Money oldBalance;
    Money newBalance;
    vector<Check> cashed;
    vector<Check> notCashed;
    vector<Money> deposit;
public: 
    Account(long oldDollar, int oldCent, long newDollar, int newCent);
    void makeDeposit(long dollar, int cent);
    void addCheck(int checkNum, long dollar, int cent, bool condition);
    void cashCheck(int checkNum);
    double newAndOldBalance();
    void totalCheckCashed();
    void totalDeposit();
    double getNewBalance();
    void totalChecksNotCashed();
    double getOldBalance();
};

Account::Account(long oldDollar, int oldCent, long newDollar, int newCent) {
    oldBalance = Money(oldDollar, oldCent);
    newBalance = Money(newDollar, newCent);
}

void Account::makeDeposit(long dollar, int cent) {
    Money temp(dollar, cent);
    deposit.push_back(temp);
    oldBalance = add(oldBalance, temp);
}

void Account::addCheck(int checkNum, long dollar, int cent, bool condition) {
    Check temp(checkNum, dollar, cent, condition);
    notCashed.push_back(temp);
}

void Account::cashCheck(int checkNum) {
    for(int i = 0; i < notCashed.size(); i++) {
        if(notCashed[i].getCheckNum() == checkNum) {
            notCashed[i].setCheckCondition(true);
            Check temp = notCashed[i];
            cashed.push_back(temp);

            // Check amount
            double check = notCashed[i].getCheckAmount();
            long dollar = (long)check;
            int cent = (int)((check-dollar)*100);

            // Old Balance
            double currBalance = oldBalance.getValue();
            long currDollar = (long)currBalance;
            int currCent = (int)((currBalance-currDollar)*100);

            // New Balance of Old Balance
            long newDollar = currDollar - dollar;
            int newCent = currCent - cent;
            if (newCent < 0) {
                newCent += 100;
                newDollar -= 1;
            }

            Money result(newDollar, newCent);
            oldBalance = result;
            notCashed.erase(notCashed.begin()+i);
            break;
        }
    }
}

double Account::newAndOldBalance() {
    double temp = oldBalance.getValue() - newBalance.getValue();
    return temp;
}

void Account::totalCheckCashed() {
    cout << "Checks cashed: " << endl;
    double totalCheck = 0;
    for(int i = 0; i < cashed.size(); i++) {
        cout << "\n";
        cashed[i].printCheckInfo();
        totalCheck += cashed[i].getCheckAmount();
    }
    cout << "\n";
    cout << "Total amount cashed: " << totalCheck;
}

void Account::totalDeposit() {
    double totalDeposit= 0;
    for(int i = 0; i < deposit.size(); i++) {
        totalDeposit += deposit[i].getValue();
    }
    cout << "Total deposit made: " << totalDeposit;
}

double Account::getNewBalance() {
    return newBalance.getValue();
}

void Account::totalChecksNotCashed() {
    cout << "Checks not cashed: " << endl;
    double totalCheck = 0;
    for(int i = 0; i < notCashed.size(); i++) {
        cout << "\n";
        notCashed[i].printCheckInfo();
        totalCheck += notCashed[i].getCheckAmount();
    }
    cout << "\n";
    cout << "Total amount not cashed: " << totalCheck << "\n";
}

double Account::getOldBalance() {
    return oldBalance.getValue();
}

int main() {
    // Account a1(120, 43, 80, 89);
    long dollar;
    int cent;
    cout << "Enter following account info: " << endl;
    cout << "Dollar of old balance: ";
    cin >> dollar;
    cout << "Cent of old balance: ";
    cin >> cent;
    long nDollar;
    int nCent;
    cout << "Dollar of new balance: ";
    cin >> nDollar;
    cout << "Cent of new balance: ";
    cin >> nCent;
    Account a1(dollar, cent, nDollar, nCent);

    int choice;
    int checkNum;
    while (true) {
        cout << "\n";
        cout << "(1) Check old account balance" << endl;
        cout << "(2) Check new account balance" << endl;
        cout << "(3) Make deposit" << endl;
        cout << "(4) Add check" << endl;
        cout << "(5) Cash check" << endl;
        cout << "(6) Check cashed checks" << endl;
        cout << "(7) Check not cashed checks" << endl;
        cout << "(8) Check total deposits" << endl;
        cout << "(9) Check old and new account balance difference" << endl;
        cout << "(10) Stop" << endl;
        cout << "Enter the number of the services or transaction you wish to be performed: ";
        cin >> choice;
        if (choice < 1 || choice > 10) {
            cout << "Invalid number. Please re-enter your choice.";
            continue;
        }
        switch(choice) {
            case 1: 
                cout << "Old Account Balance: $" << a1.getOldBalance() << endl;
                break;
            case 2:
                cout << "New Account Balance: $" << a1.getOldBalance() << endl;
                break;
            case 3: 
                cout << "Enter dollars of the deposit: ";
                cin >> dollar;
                cout << "Enter cents of the deposit: ";
                cin >> cent;
                a1.makeDeposit(dollar, cent);
                cout << "Deposit made successfully" << endl;
                break;
            case 4:
                cout << "Enter check number: ";
                cin >> checkNum;
                cout << "Enter dollars of the check amount: ";
                cin >> dollar;
                cout << "Enter cents of the check amount: ";
                cin >> cent;
                a1.addCheck(checkNum, dollar, cent, false);
                cout << "Check added successfully" << endl;
                break;
            case 5:
                cout << "Enter the number of the check you want to cash: ";
                cin >> checkNum;
                a1.cashCheck(checkNum);
                cout << "Check cashed successfully";
                break;
            case 6:
                a1.totalCheckCashed();
                break;
            case 7:
                a1.totalChecksNotCashed();
                break;
            case 8:
                a1.totalDeposit();
                break;
            case 9:
                cout << "New and old account balance difference: $" << a1.newAndOldBalance() << endl;
                break;
            case 10:
                exit(1);
        }
    }
}