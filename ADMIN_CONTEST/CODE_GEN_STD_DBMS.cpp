/*
Description
In DataBase Management Systems, we need to generate the keys for records created. In many cases, a key is generated by generating a non-negative integer and is standardized under a string with fixed length L (by filling characters 0 at the beginning of the integer util the length is equal to L). For example, if the fixed-length L is 5, the key generated from 123 is the string 00123.
Given a positive integer n and L, and a sequence of integers a1, a2, ..., an. Write a program for generating corresponding keys k1, k2, ..., kn.

Input

    Line 1: contains n and L (1 <= n <= 1000000, 2 <= L <= 50)
    Line i+1 (i = 1,...,n): contains ai (1 <= ai <= 2000000), ai < 10L


Output

    Line i (i = 1,..., n): contains the key ki


Example
Input
5 6
54
39
40
78
1

Output
000054
000039
000040
000078
000001
*/

#include<bits/stdc++.h>

using namespace std;

int n, L;

int main() {
    cin >> n >> L;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        string s = to_string(a);
        while(s.size() < L) {
            s = "0" + s;
        }
        cout << s << endl;
    }
    return 0;
}