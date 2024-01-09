/*
Description
Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xN (0≤ xi ≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input

    The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases.
    Subsequent lines are T test cases with the following format:
    Line 1: Two space-separated integers: N and C
    Lines 2: contains  x1, x2, . . . , xN


Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1
2
8
4
9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define N 100001

using namespace std;

int t, n, c, ans;
int x[N];
int Left, Right, Mid;

bool Check(int Mid)
{
    int cnt = 1;
    int tmp = x[1];
    loop(i, 2, n)
    {
        if (x[i] - tmp >= Mid)
        {
            cnt++;
            tmp = x[i];
        }
    }
    return cnt >= c;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        loop(i, 1, n) cin >> x[i];
        sort(x + 1, x + n + 1);
        // for (int i = 1; i <= n; i++)
        //     cout << x[i] << " ";
        // cout << endl;
        Left = 1;
        Right = (x[n] - x[1]) / (c - 1);
        ans = INT_MIN;

        while (Left <= Right)
        {
            Mid = (Left + Right) / 2;
            cout << "Left: " << Left << " Right: " << Right << " Mid: " << Mid << endl;
            if (Check(Mid))
            {
                ans = Mid;
                cout << "Ans: " << ans << endl;
                Left = Mid + 1;
            }
            else
            {
                Right = Mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}