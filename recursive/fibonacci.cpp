#include <bits/stdc++.h>

using namespace std;

int n;
int F[100];
int check[100] = {0};

int fibonacci(int n)
{
    if (check[n])
        return F[n];
    else
    {
        if (n <= 1)
        {
            F[n] = n;
            return F[n];
            check[n] = 1;
        }
        else
        {
            F[n] = fibonacci(n - 1) + fibonacci(n - 2);
            return F[n];
            check[n] = 1;
        }
    }
}

int main()
{
    cin >> n;
    F[0] = 1;
    fibonacci(n);
    for (int i = 0; i < n; i++)
    {
        cout << F[i] << " ";
    }
    return 0;
}