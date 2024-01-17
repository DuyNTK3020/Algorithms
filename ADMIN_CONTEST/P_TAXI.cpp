#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int f = 0;
int Fmin = INT_MAX;
int Fmax = INT_MIN;
int n;
int c[N][N];
bool visited[N];
int d[N]; // luu thanh pho hien thoi
int load = 0;
int c_min = INT_MAX;

void input()
{
    cin >> n;
    loop(i, 0, 2 * n)
    {
        loop(j, 0, 2 * n)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
            {
                c_min = min(c[i][j], c_min);
            }
        }
    }
}
bool check(int v, int k)
{
    if (visited[v])
        return false;
    if (v <= n)
    {
        if (load == 0)
            return true;
    }
    else
    {
        if (load == 1)
            return visited[v - n];
    }
    return false;
}

void solution()
{
    Fmin = min(f + c[d[2 * n]][0], Fmin);
    // loop(i, 1, 2 * n)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << endl;
}
void Try(int k)
{
    loop(v, 1, 2 * n)
    {
        if (check(v, k))
        {
            d[k] = v;
            f += c[d[k - 1]][v];
            visited[v] = true;
            if (v <= n)
            {
                load++;
            }
            else
            {
                load--;
            }
            if (k == 2 * n)
            {
                solution();
            }
            else
            {
                if (Fmin > f + c_min * (2 * n + 1 - k))
                    Try(k + 1);
            }
            f -= c[d[k - 1]][v];
            visited[v] = false;
            if (v <= n)
            {
                load--;
            }
            else
            {
                load++;
            }
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
    Try(1);
    cout << Fmin;
    return 0;
}