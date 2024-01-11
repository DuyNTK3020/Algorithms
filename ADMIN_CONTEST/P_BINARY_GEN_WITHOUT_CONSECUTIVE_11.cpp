/*
Description
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input

    Line 1: contains an integer n (1 <= n <= 20)

Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    printf("\n");
}

void Try(int k)
{
    for (int i = 0; i < 2; i++)
    {
        arr[k] = i;
        if (arr[k - 1] == 1 && arr[k] == 1) {
            continue;
        }
        if (k == n - 1)
        {
            printSolution();
        }
        else
        {
            Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(0);
    return 0;
}
