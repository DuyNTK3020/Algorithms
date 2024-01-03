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
#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int n;
vector<vector<int>> matrix(MAX, vector<int>(MAX, 0));
int X[MAX];
int visited[MAX] = {0};
int minD = INT_MAX;
int d = 0;
int minMatrix = INT_MAX;

bool check(int v, int k) {
    if (visited[v] == 0 && k < n) return true;
    return false;
}

void Try(int k) {
    for (int v = 1; v < n; v++) {
        if (check(v,k)) {
            X[k] = v;
            visited[v] = 1;
            d += matrix[X[k-1]][X[k]];
            if (k == n - 1) {
                minD = min(minD, d + matrix[X[k]][X[0]]);
            } else if (d + minMatrix * (n-k) < minD) {
                Try(k+1);
            }
            visited[v] = 0;
            d -= matrix[X[k-1]][X[k]];
        }
    }
}

int main() {
    cin >> n;
    matrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) {
                minMatrix = min(minMatrix, matrix[i][j]);
            }
        }
    }
    X[0] = 0;
    visited[0] = 1;
    Try(1);
    cout << minD << endl;
    return 0;    
}