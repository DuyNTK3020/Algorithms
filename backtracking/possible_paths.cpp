#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<int> path;

void printPath()
{
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;
}

bool check(int i, int j)
{
    if (i < n && j < m) return true;
    return false;
}

void Try(int i, int j)
{
    if (check(i, j)) {
        path.push_back(arr[i][j]);
        if (i == n - 1 && j == m - 1)
            printPath();
        if (i + 1 < n) Try(i + 1, j);
        if (j + 1 < m) Try(i, j + 1);
        path.pop_back();
        return;
    }
}

int main()
{
    cin >> n >> m;
    arr.resize(n, vector<int>(m)); // Khởi tạo kích thước cho arr ở đây

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    Try(0, 0);
    return 0;
}
