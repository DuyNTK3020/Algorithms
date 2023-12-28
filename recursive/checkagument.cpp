#include <bits/stdc++.h>

using namespace std;

int n;
string str;

bool fcheck(int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return fcheck(start+1, end-1);
}

int main()
{
    cin >> str;
    cout << fcheck(0, str.length()-1) << endl;
    return 0;
}