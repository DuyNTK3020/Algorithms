/*
Description
Given a positive integer n and n positive integers a1, a2, ..., an. Compute the number of positive integer solutions to the equation:
                          a1X1 + a2X2 + . . . + anXn = M

Input

    Dòng 1: n và M
    Dòng 2: a1, a2, ..., an

Output
   Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6
*/

#include <bits/stdc++.h>
using namespace std;

int n, M;
int T = 0, result = 0;
int arr[100];
int X[100];

bool check(int v, int k) {
    T += v * arr[k];
    if (k < n) {
        return T < M;
    } else {
        return T == M;
    }
}

void Try(int k) {
    for (int v = 1; v <= M - T; v++) {
        if (check(v, k)) {
            X[k] = v;
            if (k == n) {
                result++;
            } else {
                Try(k + 1);
            }
            T -= v * arr[k];
        } else {
            T -= v * arr[k];
        }
    }
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    Try(1);
    cout << result;
    return 0;
}
