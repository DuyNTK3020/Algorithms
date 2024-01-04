/*
Description
Given a sequence of n tasks 1, 2, ..., n. The task i has starting time is ti which is under the format YYYY-MM-DD hh:mm:ss (for example: 2021-06-03 10:34:21) and the duration Di (in seconds). Compute the finising time of n tasks.

Input

    The first block is the sequence of continuous days, each day is in a line under the format YYYY-MM-DD. The first block is terminated by a line containing the * character
    The second block contains n lines, each line i (i = 1,...,n) contains ti and Di

Output
Each line i (i = 1, ..., n) contains the finishing time of the task i under the format YYYY-MM-DD hh:mm:ss

Example
Input
2020-12-29
2020-12-30
2020-12-31
2021-01-01
2021-01-02
2021-01-03
*
2020-12-30 21:23:02 1
2020-12-30 21:33:02 86400
2020-12-30 21:33:02 172800
***
Output
2020-12-30 21:23:03
2020-12-31 21:33:02
2021-01-01 21:33:02
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> date;

int main() {
    while(true) {
        string str;
        cin >> str;
        if(str == "*") break;
        date.push_back(str);
    }
    while(true) {
        string str;
        cin >> str;
        if(str == "***") break;
        int hh, mm, ss, dur;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &dur);
        int t = hh*3600 + mm*60 + ss + dur;
        int nextDay = t/3600/24;
        t -= nextDay*3600*24;
        hh = t / 3600;
        t -= hh*3600;
        mm = t / 60;
        t -= mm*60;
        ss = t;
        if (nextDay == 0) {
            cout << str;
            printf(" %02d:%02d:%02d\n", hh, mm, ss);
        } else  {
            cout << *(find(date.begin(),date.end(),str) + nextDay);
            printf(" %02d:%02d:%02d\n", hh, mm, ss);
        }
    }
    return 0;
}