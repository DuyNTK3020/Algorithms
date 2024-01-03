/*
Description
Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
Input

    Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)

Output

    Write in each line X1, X2, ..., Xn separated by a SPACE character

Example
Input
3  5
Output
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1
*/

#include <bits/stdc++.h>
#define MAX 15

using namespace std;

int n,M;
int X[MAX];
int T = 0;

void printSol() {
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
    T += v;
    if (T == M && k == n - 1) return true;
    if (T < M && k < n - 1) return true;
    return false;
}

void Try(int k) {
    for (int v = 1; v <= M - T; v++) {
        if(check(v,k)) {
            X[k] = v;
            if (k == n - 1) {
                printSol();
            } else {
                Try(k + 1);
            }
        }
        T -= v;
    }
}

int main() {
    cin >> n >> M;
    Try(0);
    return 0;
}