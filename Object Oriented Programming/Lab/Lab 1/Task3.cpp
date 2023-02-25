#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  fstream outFile;
  outFile.open("list.txt", ios::in);
  vector<string> wordList;
  string temp;
  
  while(outFile) {
    getline(outFile, temp);
    if (temp == "-1") {
      break;
    }
    wordList.push_back(temp);
  }

  // Test for vector:
  // for(int i = 0; i < wordList.size(); i++) {
  //   cout << wordList[i] << endl;
  // }
  srand(time(NULL));
  int num = rand() % wordList.size();
  string randWord = wordList[num];
  
  vector<int> randomNum;
  for(int i = 0; i < 3; i++) {
    int num = rand() % 100;
  }
  
  int num = rand() % 100;
  //cout << num;
}