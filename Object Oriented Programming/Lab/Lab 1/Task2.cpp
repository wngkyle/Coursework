#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Enter the Expression: ";
  string expression;
  getline(cin, expression);
  string expression2 = expression;
  int index = expression.find(" ");
  int operand1 = stoi(expression.substr(0,index));
  expression = expression.substr(index+1);
  string op = expression.substr(0, 1);
  int operand2 = stoi(expression.substr(2));
  int result = 0;
  
  if (op == "+") {
    result = operand1 + operand2;
  } else if (op == "-") {
    result = operand1 - operand2;
  } else if (op == "*") {
    result = operand1 * operand2;
  } else {
    result = operand1 / operand2;
  }

  cout << expression2 << " = " << result;
}