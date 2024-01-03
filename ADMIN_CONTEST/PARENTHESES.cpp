/*
Description
Given a string containing only characters (, ), [, ] {, }. Write a program that check whether the string is correct in expression. 
Example:
([]{()}()[]): correct
([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to 10^6)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example:
input
(()[][]{}){}{}[][]({[]()})
output
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> c;
    char temp;
    while (cin.get(temp)) {
        if (temp == '\n') break;
        if (temp == '{' || temp == '[' || temp == '(') {
            c.push(temp);
        } else if (temp == '}' || temp == ']' || temp == ')') {
            if (c.empty()) {
                cout << 0 << endl;
                return 0;
            }
            if (c.top() == '{' && temp == '}') {
                c.pop();
            } else if (c.top() == '[' && temp == ']') {
                c.pop();
            } else if (c.top() == '(' && temp == ')') {
                c.pop();
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    if (c.empty()) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}