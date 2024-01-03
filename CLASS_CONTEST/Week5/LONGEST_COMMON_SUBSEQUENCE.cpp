/*
Description
Denote X = X1, X2, …, Xn, a subsequence of X is created by removing some element from X.  Given two sequences X = X1, X2, …, Xn and Y = Y1, Y2, …, Ym. Find a common subsequence of X and Y such that the length is the longest.
Input

    Line 1: two positive integers n and m (1 <= n,m <= 10000)
    Line 2: n integers X1, X2, …, Xn
    Line 3:  m integers Y1, Y2, …, Ym

Output

    Length of the longest subsequence of X and Y

Example
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5
*/

#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int n, m;
int X[MAX], Y[MAX];
int matrix[MAX][MAX] = {0};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < m; i++)
        cin >> Y[i];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (X[j - 1] == Y[i - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    cout << matrix[m][n];
    return 0;
}