/*
Description
Given an integers sequence a=(a1, a2,…, an). A subsequence of aa is defined to be ai, ai+1,…, aj. The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
Input

    Line 1 contains n (1≤n≤106)
    Line 2 contains a1,…,an (−500≤ai≤500)

Output
Write the weight of the highest subsequence found.
Example
input
10
3 -1 -3 5 2 5 0 -1 5 4
output
20
*/

#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

long long int n;
long long int a[MAX];
long long int maxSubHere = 0;
long long int maxSub = 0;

int main()
{
    cin >> n;
    for (long long int i = 0; i < n; i++)
        cin >> a[i];
    for (long long int i = 0; i < n; i++)
    {
        maxSubHere += a[i];
        if (maxSubHere > maxSub)
            maxSub = maxSubHere;
        if (maxSubHere < 0)
            maxSubHere = 0;
    }
    cout << maxSub << endl;
    return 0;
}