#include <bits/stdc++.h>
#define N 50
int n, K;
int c[N][N];

using namespace std;

int x[2 * N + 1];
bool visited[2 * N + 1];
int f = 0;
int load = 0;
int Fmin = INT_MAX;
int cmin = INT_MAX;
void input()
{
    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
            {
                cmin = min(c[i][j], cmin);
            }
        }
    }
    // g = f + cmin*(2n-k+1)
}

void printSolution()
{
    for (int i = 0; i <= 2 * n; i++)
        cout << x[i] << "  ";
    cout << x[0] << endl;
}

void solution()
{
    f += c[x[2 * n]][0];
    Fmin = min(f, Fmin);
    f -= c[x[2 * n]][0];
    // printSolution();
}

bool check(int v, int k)
{
    if (load == 0 && v > n)
        return false;
    if (!visited[v])
    {
        if (v > n)
        {
            // if (load >= K)
            //     return false;
            return visited[v - n];
        }
    }
    return !visited[v];
}

void Try(int k) // gan thanh pho cho lo trinh x[k]
{
    // int start;
    // if (load == K)
    // {
    //     start = n + 1;
    // }
    for (int v = ((load == K) ? (n + 1) : 1); v <= 2 * n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = true;
            f += c[x[k - 1]][x[k]];
            if (v >= 1 && v <= n)
                load++;
            else
                load--;
            if (k == 2 * n)
            {
                solution();
            }
            else
            {
                if ((f + cmin * (2 * n - k + 1)) < Fmin)
                {
                    Try(k + 1);
                }
            }
            visited[v] = false;
            f -= c[x[k - 1]][x[k]];
            if (v >= 1 && v <= n)
                load--;
            else
                load++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    x[0] = 0;
    Try(1);
    cout << Fmin << endl;
    // int sum = c[0][3] + c[3][2] + c[2][6] + c[6][4] + c[4][1] + c[1][5] + c[5][0];
    // cout << sum << endl;
    return 0;
}