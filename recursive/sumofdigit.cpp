#include<bits/stdc++.h>

using namespace std;

int n;

int recursive(int n) {
    if (n == 0) return 0;
    else {
        return n % 10 + recursive(n / 10);
    }
}

int main() {
    cin >> n;
    cout << recursive(n) << endl;
    return 0;
}