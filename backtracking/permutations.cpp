#include <bits/stdc++.h>

using namespace std;

string str;
string result;

void Try(int k, int n)
{
    for (int v = k; v < n; v++) {
        if (k == n - 1) {
            cout << str << endl;
        } else {
            swap(str[k], str[v]);
            Try(k + 1, n);
            swap(str[k], str[v]);
        }
    }
}

int main()
{
    cin >> str;
    int n = str.size();
    Try(0, n);
    return 0;
}