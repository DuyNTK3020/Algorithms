#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int a[MAX];
int b[MAX];
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[a[i]] != 0) {
            sum += b[a[i]];
        }
        b[a[i]]++;
    }
    cout << sum;
}