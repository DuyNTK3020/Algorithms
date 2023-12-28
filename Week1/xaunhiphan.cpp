#include<bits/stdc++.h>

using namespace std;
int n;
int coutzero = 0;
int coutn = 0;
int X[100] = {0};

void printSol() {
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}

bool check (int i, int n) {
    if (coutzero == 6) return false;
    return true;
}

void subbit(int k) {
    for (int i = 0; i <= 1; i++) {
        if (check(i,k)) {
            X[k] = i;
            if (i == 0) coutzero++;
            if (k == n -1) {
                coutn++;
                printSol();
            } else subbit(k + 1);
            if (i == 0) coutzero--;
        }
    }
}

int main()
{
    cin >> n;

    subbit(0);
    return 0;
}