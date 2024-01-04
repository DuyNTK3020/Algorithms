/*
Description
A shipper visits all points 1, 2, 3, ..., n (each point is visited exactly once) for delivering packages and comes back to the starting point. There is a precedence constraint between points on the route of shipper which is represented by a list of m pairs (i,j): point i must be located before point j on the route (i, j = 1, 2, ..., n). A route of shipper is feasible if it is a permutation of 1, 2, ..., n and satisfies the precedence constraint. The travel distance from point i to point j is d(i,j) (i,j = 1,...,n). Write a program that checks if a sequence x1, x2, ..., xn is a feasible route of the shipper and computes the total travel distance of that route.

Input

    Line 1: contains a positive integer n (1 <= n <= 1000)
    Line 2: contains n positive integers x1, x2, ..., xn
    Line i + 2 (i = 1,...,n): contains the ith row of the distance matrix d
    Line n+3: contains a positive integer m (1 <= m <= 1000000)
    Line k + n + 3 (k = 1,...,m): contains two positive integers i and j (1 <= i, j <= n): point i must be located before point j on the route


Output

    Write the total travel distance of the route x1, ..., xn if it is feasible, or write -1 if the sequence x1, ..., xn is not feasible.


Example
Input
4
1 2 3 4
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4
Output
9


Input
4
4 2 3 1
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4
Output
-1
*/

#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n, m;
int x[1005];
int d[1005][1005];
int totalDistance = 0;
int check[1005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        check[x[i]] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    
    for (int i = 1; i < n; i++) 
        totalDistance += d[x[i]][x[i+1]];
    totalDistance += d[x[n]][x[1]];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (check[a] > check[b]) {
            cout << -1;
            return 0;
        }
    }
    cout << totalDistance << endl;
    return 0;
}