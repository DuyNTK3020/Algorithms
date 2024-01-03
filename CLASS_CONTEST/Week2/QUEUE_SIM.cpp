/*
Description
Perform a sequence of operations over a queue, each element is an integer:

    PUSH v: push a value v into the queue
    POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)

Input
Each line contains a command (operration) of type

    PUSH  v
    POP

Output

    Write the results of POP operations (each result is written in a line)

Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> myQueue;
    string cmd;
    while(true) {
        cin >> cmd;
        if (cmd == "#") break;
        if (cmd == "PUSH") {
            int input;
            cin >> input;
            myQueue.push(input);
        }
        if (cmd == "POP") {
            if(myQueue.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << myQueue.front() << endl;
                myQueue.pop();
            }
        }
    }
    return 0;
}