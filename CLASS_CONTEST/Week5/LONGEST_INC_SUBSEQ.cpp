/*
Description
Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.

Input

    Line 1: contains a positive integer n (1 <= n <= 10000)
    Line 2: contains n elements of the given sequence (1 <= ai <= 10000)

Output
The length of the subsequence found.

Example
Input 
6
5 8 2 8 10 10 

Output
3
*/

#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int n;
int a[MAX];
int longestSubsequence[MAX];
int result = INT_MIN;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        longestSubsequence[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                longestSubsequence[i] = max(longestSubsequence[i], longestSubsequence[j] + 1);
            }
        }
        result = max(result, longestSubsequence[i]);
    }
    cout << result << endl;
    return 0;
}