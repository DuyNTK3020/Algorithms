#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long a1 = a / 10;
    unsigned long long b1 = b / 10;
    unsigned long long c = a % 10 + b % 10;
    unsigned long long e;
    if (c > 9)
    {
        e = a1 + b1 + 1;
        c = c % 10;
    }
    else
        e = a1 + b1;
    if (e)
    {
        cout << e << c;
    }
    else
        cout << c;
    return 0;
}
