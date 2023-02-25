#include <iostream>
using namespace std;


void Sort(int array[], int len)
{
  for (int i = 0; i < len-1; i++) {
    int min = i;
    for (int j = i+1; j < len; j++) {
      if (array[j] < array[min]) {
        min = j;
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;

        int* ptr2 = new int[len];
        for(int j=0 ;j< len; j++) {
          ptr2[j]=array[i];
        }
      }
    } 
  }
}

int main() {
  int array[] = {-3,2,6,1, 8};
  int length = 5;

  cout << "Before : "<< endl;
  for (int i= 0; i < length; i++)
    {
      cout << array[i] << " ";
    }
  Sort(array, length);

  cout << endl << "After: "<< endl;
   for (int i= 0; i < length; i++)
    {
      cout << array[i] << " ";
    }
}