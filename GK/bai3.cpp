#include <bits/stdc++.h>
using namespace std;

int n;
int bag[21];
int check[21];
int sum = 0;
int aim;
int curSum = 0;
int Dmin = INT_MAX;

void Try(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            check[i] = 1;
            curSum += bag[i];
            if (curSum >= aim)
            {
                curSum -= bag[i];
                check[i] = 0;
                Dmin = min(Dmin, sum - 2 * curSum);
                return;
            }
            Try(k + 1);
            curSum -= bag[i];
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> bag[i];
        sum += bag[i];
    }
    aim = sum / 2;

    Try(0);
    cout << Dmin;
}