#include <bits/stdc++.h>
using namespace std;
int n;
int xmax = INT_MIN, ymax = INT_MIN;
long long cost[1001][1001];
long long dp[1001][1001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        xmax = max(x, xmax);
        ymax = max(y, ymax);
        cin >> cost[x][y];
    }

    dp[1][1] = cost[1][1];

    for (int i = 2; i <= xmax; i++)
    {
        dp[i][1] = dp[i - 1][1] + cost[i][1];
    }

    for (int j = 2; j <= ymax; j++)
    {
        dp[1][j] = dp[1][j - 1] + cost[1][j];
    }

    for (int i = 2; i <= xmax; i++)
    {
        for (int j = 2; j <= ymax; j++)
        {
            dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + cost[i][j];
        }
    }
    cout << dp[xmax][ymax];
    return 0;
}
