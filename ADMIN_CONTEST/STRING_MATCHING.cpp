/*
Description
Given a string T and a pattern P which is also a string. Find the number of occurrences of P in T.
Input

    Line 1: contains string P (length is less than or equals to 105)
    Line 2: contains the string T (length is less than or equals to 106)

Output

    Write the number of occurrences of P in T

Exmple
Input
computer
There are so many kinds of computers today including high performance computers, laptop computers. Mobile phones are also computers
Output
4
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string P;
    string T;
    int count = 0;
    getline(cin, P);
    getline(cin, T);
    size_t pos = T.find(P);
    while (pos != string::npos) {
        count++;
        pos = T.find(P, pos + 1);
    }

    cout << count << endl;

    return 0;
}
