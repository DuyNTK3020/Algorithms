/*
Description
Given two positive integers a and b. Compute a^b mod (10^9 + 7)
Input
One line contains two integers a and b (1 <= a,b <= 18446744073709551614)
Output
The value a^b mod (10^9+7)
Example
Input
2  3
Output
8
*/

#include <bits/stdc++.h>

using namespace std;

const int modules = 1000000007;

int compute(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return 1;
    a = a % modules;
    unsigned long long tmp = compute(a, b / 2) % modules;
    unsigned long long c = (tmp * tmp) % modules;
    if (b % 2 == 1)
        c = (c * a) % modules;
    return c;
}

int main()
{
    unsigned long long a, b;
    // freopen("EXPMODinput.txt","r",stdin);
    // 	scanf("%llu %llu",&a,&b);
    cin >> a >> b;
    printf("%llu", compute(a, b));
    return 0;
}