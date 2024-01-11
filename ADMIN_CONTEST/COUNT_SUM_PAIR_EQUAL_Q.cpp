/*
Description
Given a sequence of distinct integers a1, a2, …, an and an integer Q. Count number M of pairs (i, j) such that 1 ≤ i< j ≤ n and ai+ aj= Q
Input
•Line 1: contains two integers nand Q (1 <= n,Q<= 106)
•Line 2: contains a1, a2, …, an
Ouput
•Write the value of M
Example
Input
5 8
4 6 5 3 2
Output
2
*/

#include <bits/stdc++.h>

using namespace std;

int n, Q, num, dem = 0;

int main()
{
    cin >> n >> Q;
    unordered_map<int,int> map;

    for (int i = 0; i< n;i++) {
        cin >> num;
        if (map.find(Q-num) != map.end()) {
            dem+=map[Q-num];
        }
        map[num]++;
    }
    cout << dem << endl;
    return 0;
}
