/*
Description
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input

    Line 1: two positive integers k and n (1 <= k,n <= 999)

Output
Write te value C(k,n) modulo 109+7.
Example
Input
3  5
Output
10
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Hàm tính lũy thừa a^b % MOD
int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (1LL * result * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Hàm tính n!
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (1LL * result * i) % MOD;
    }
    return result;
}

// Hàm tính C(k, n) = n! / (k! * (n-k)!)
int binomialCoefficient(int k, int n) {
    int numerator = factorial(n);
    int denominator = (1LL * factorial(k) * factorial(n - k)) % MOD;

    // Tính nghịch đảo của denominator theo MOD
    int inverse_denominator = power(denominator, MOD - 2);

    // Kết quả là tích của numerator và nghịch đảo của denominator
    int result = (1LL * numerator * inverse_denominator) % MOD;
    return result;
}

int main() {
    int k, n;
    cin >> k >> n;

    int result = binomialCoefficient(k, n);
    cout << result << endl;

    return 0;
}
