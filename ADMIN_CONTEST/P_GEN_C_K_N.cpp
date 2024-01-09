/*
Description
Given 2 positive integers k and n. Write a program tat generates all k-combinations of 1, 2, ..., n in a lexicographic order.

Example
Input
2 4
Output
1 2
1 3
1 4
2 3
2 4
3 4
*/

#include <bits/stdc++.h>
using namespace std;

int k, n, result[1000];

void printSol()
{
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    cout << endl;
}

void Try(int m, int start)
{
    if (m == k) {
        printSol();
        return;
    }
    for (int i = start; i <= n; i++) {
        result[m] = i;
        Try(m + 1, i + 1);
    }
}

int main()
{
    cin >> k >> n;
    Try(0, 1);
    return 0;
}