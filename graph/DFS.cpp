#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u) {
    cout << u << " ";
    // Danh dau u da dc tham
    visited[u] = true;
    for (int v : adj[u]) {
        // Neu dinh v ch duoc tham
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
    return 0;
}