#include <iostream>
#include <list>
#include <vector>
#include <stdio.h> 
#include <algorithm>     
#include <assert.h> 

using namespace std;


void swap(int &a, int &b) { 
    int tmp = a; 
    a = b; 
    b = tmp; 
}

void messup(int *c) { 
    int save = *c;
    --c; 
    *c = save; 
}

void test(int &x, int &y) {
    x = y;
}

int main() {

    int x = 1, y = 2, z = 3;
    /* 1.1 what does the following print? */
    int *a = &x, *b = &y; 
    cout << "1.1: " << *a << " " << *b << endl;

    /* 1.2 what does the following print? */
    swap(a,b); 
    cout << "1.2: " << a << " " << b << endl;

    /* 1.3 how about this? */
    cout << "1.3: " << x << " " << y << endl;

    /* 1.4 and that? Please also give your opinion on the code */
    messup(&z); 
    cout << "1.4: " << x << " " << y << endl;

    // int x = 0;
    // int y = 10;
    // cout << x << endl;
    // test(x, y);
    // cout << x << endl;


    // // initialize a few arrays
    // int A1[6] = { 0, 1, 2, 3, 4, 5 };
    // int A2[6] = { 5, 4, 3, 2, 1, 0 };
    // int A3[6] = { 3, 0, 3, 1, 1, -2 };

    // // V is a vector that contains 5 4 3 2 1 0
    // vector<int> V( A2, A2+6 );

    // // L is a list that contains 3 0 3 1 1 -2
    // list<int> L;
    // L.push_back(3); L.push_back(0); L.push_back(3);
    // L.push_back(1); L.push_back(1); L.push_back(-2);

    // // S is a string that contains "A man, a plan, a canal: Panama!"
    // string S( " A man, a plan, a canal: Panama!" );

    // // 5.0  count the number of 3's in L
    // assert( count(L.begin(), L.end(), 3) == 2);

    // // As an example, your solution should say
    // // assert( count( L.begin(), L.end(), 3 ) == 2);

    // // 5.1  using std::find, check that V does not contain 6
    // assert( find( V.begin(), V.end(), 6 ) == V.end() );

    // // 5.2  test if L contains two adjacent identical numbers
    // list<int>::iterator it1 = adjacent_find( L.begin(), L.end() );
    // if (it1 == L.end())
    //     cout << "No adjacent number found\n";
    // else
    //     cout << "Found two adjacent numbers equal to " << *it1 << "\n";

    // // 5.3  find first punctuation character in S
    // string punctuation( ":;,.!?" );
    // cout << "First punctuation character in " << S << " is "
    //         << *(std::find_first_of( S.begin(), S.end(), punctuation.begin(), punctuation.end() ))
    //         << std::endl;
    
    // // 5.4  check that L and A3 contain the same elements in same order
    // assert( equal( L.begin(), L.end(), A3 ) );

    // // 5.5 fill A3 with -1
    // fill( A3, A3+6, -1 );

    // // 5.6  replace every space in S by the underscore '_'
    // replace( S.begin(), S.end(), " ", "-" );

    // // 5.7  check that S is a palindrom by reversing S3
    // string S2( "amanaplanacanalpanama" );
    // string S3( S2 );
    // reverse( S3.begin(), S.end() );
    // assert( std::equal( S2.begin(), S2.end(), S3.begin()) );

    // // 5.8  copy every element of A2 into A3, check the result
    // copy( A2, A2+6, A3 );
    // assert( std::equal( A2, A2+6, A3 ) );

    // // 5.9  sort A3, check that it gives the same as A1
    // sort( A3, A3+6 );
    // assert( equal( A1, A1+6, A3 ) );

    // // 5.10 find the smallest element in V
    // assert( min_element( V.begin(), V.end() ) == &V[5] );

    // // 5.11 find the 3rd smaller element in V
    // std::nth_element( V.begin(), V.begin()+2, V.end() );
    // assert( V[0] < 2 && V[1] < 2 && V[2] == 2 );


}