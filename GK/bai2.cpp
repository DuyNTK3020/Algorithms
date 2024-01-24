#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int k, n, year, result[1000];
int a[MAX];
int tong = 0;
int dem = 0;

void printSol()
{
    // for (int i = 0; i < k; i++)
    //     cout << result[i] << " ";
    // cout << endl;
    dem++;
}

void Try(int m, int start)
{
    if (m == k)
    {
        if (tong >= year && tong % 5 == 0)
            printSol();
        return;
    }
    for (int i = start; i < n; i++)
    {
        result[m] = a[i];
        tong += result[m];
        Try(m + 1, i + 1);
        tong -= result[m];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> year;
    for (int i = 1; i <= n; i++)
    {
        k = i;
        Try(0, 0);
    }
    cout << dem << endl;
    return 0;
}