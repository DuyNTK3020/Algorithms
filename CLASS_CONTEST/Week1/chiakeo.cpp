#include<bits/stdc++.h>

#define MAX 100

using namespace std;

int n,M;
int X[MAX];
int T = 0;

void printSol() {
    for (int i = 0; i < n; i++) {
        cout << X[i];
    }
    cout << endl;
}

bool check(int v, int k) {
    T += v;
    if (k < v) return T < M;
    else return T == M;
    return true;
}

void Try(int k) {
    for (int v = 0; v < M - T; v++) {
        if (check(v,k)) {
            X[k] = v;
            if (k == n-1) {
                printSol();
            } else {
                Try(k+1);
            }
            T -= v;
        } else {
            T -=v;
        }
    }
}

int main() {
    cin >> n >> M;

    Try(0);

    return 0;
}