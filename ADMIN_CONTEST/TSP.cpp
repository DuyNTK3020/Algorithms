/*
Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
Input

    Line 1: a positive integer n (1 <= n <= 20)
    Linr i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)

Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/

#include <bits/stdc++.h>
#define MAX 100

using namespace std;

// X[i] : số thành phố thứ i mà người đó đã đi qua
int n, c[MAX][MAX], X[MAX];
int visited[MAX] = {0};
int d = 0, ans = INT_MAX, cmin = INT_MAX;

void Try(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            X[k] = i;
            d += c[X[k - 1]][X[k]];
            if (k == n)
            {
                ans = min(ans, d + c[X[n]][X[1]]);
            }
            else if (d + (n - i + 1) * cmin < ans)
            {
                Try(k + 1);
            }
            visited[i] = 0;
            d -= c[X[k - 1]][X[k]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0)
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans;
    return 0;
}
