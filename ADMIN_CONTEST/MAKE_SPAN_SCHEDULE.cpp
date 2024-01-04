/*
Description
A project has n tasks 1,. . ., n. Task i has duration d(i) to be completed (i=1,. . ., n). There are precedence constraints between tasks represented by a set Q of pairs: for each (i,j)  in Q, task j cannot be started before the completion of task i. Compute the earliest completion time  of the project.
Input

    Line 1: contains n and m (1 <= n <= 104, 1 <= m <= 200000)
    Line 2: contains d(1),. . ., d(n) (1 <= d(i) <= 1000)
    Line i+3 (i=1,. . ., m) : contains i and j : task j cannot be started to execute before the completion of task i

Output

    Write the earliest completion time of the project.

Example
Input
9 13
5 3 1 2 6 4 3 1 4
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8

Output
18
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10005; // Số công việc tối đa
vector<int> adj[MAXN]; // Đồ thị biểu diễn mối quan hệ giữa công việc
int in_degree[MAXN]; // Bậc vào của từng công việc
int duration[MAXN]; // Thời gian thực hiện của từng công việc
int earliestCompletionTime[MAXN]; // Thời gian hoàn thành sớm nhất của từng công việc

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> duration[i];

    // Khởi tạo đồ thị và bậc vào
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // Khởi tạo queue chứa các công việc có bậc vào là 0
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            earliestCompletionTime[i] = duration[i]; // Thời gian hoàn thành sớm nhất của công việc là thời gian thực hiện
        }
    }

    // Duyệt qua các công việc và tính thời gian hoàn thành sớm nhất
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            in_degree[v]--;
            earliestCompletionTime[v] = max(earliestCompletionTime[v], earliestCompletionTime[u] + duration[v]);
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    // Tìm thời gian hoàn thành sớm nhất của dự án
    int projectTime = 0;
    for (int i = 1; i <= n; ++i)
        projectTime = max(projectTime, earliestCompletionTime[i]);

    cout << projectTime << endl;

    return 0;
}
