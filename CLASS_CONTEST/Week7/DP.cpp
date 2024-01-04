#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);

void DFS(int u)
{
    if (bVisited[u])
        return;
    bVisited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        DFS(v);
    }
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    return 0;
}