#include<bits/stdc++.h>

using namespace std;

int n;

int factorial(int n) {
    if (n == 1)  return n;
    else return n * factorial(n - 1);
}

int main()
{
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}