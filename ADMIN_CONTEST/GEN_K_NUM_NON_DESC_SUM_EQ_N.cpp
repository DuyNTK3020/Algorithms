/*
Description
Given two positive integers k and n. Write a program to generate (x1, x2, ..., xk) such that x1 <= x2 <= . . . <= xk and x1 + x2 + . . . + xk = n.
Input

    Line 1 contains: k and n (1 <= k <= n <= 40)

Output

    Each line contains: x1, x2, . . ., xk separated by a SPACE character

Example
Input
3  7
Output
1 1 5
1 2 4
1 3 3
2 2 3
*/
/*
Description
Given two positive integers k and n. Write a program to generate (x1, x2, ..., xk) such that x1 <= x2 <= . . . <= xk and x1 + x2 + . . . + xk = n.
Input

    Line 1 contains: k and n (1 <= k <= n <= 40)

Output

    Each line contains: x1, x2, . . ., xk separated by a SPACE character

Example
Input
3  7
Output
1 1 5
1 2 4
1 3 3
2 2 3
*/

#include <bits/stdc++.h>
using namespace std;

int k, n;
int T = 0;
int result[41];

void printSol()
{
    for (int i = 1; i <= k; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

bool check(int x, int i)
{
    T += i;
    if (x < k)
        return T <= n;
    else
        return T == n;
    return true;
}

void Try(int x)
{
    for (int i = result[x - 1]; i <= n; i++)
    {
        if (check(x, i))
        {
            result[x] = i;
            if (x == k)
                printSol();
            else
                Try(x + 1);
        }
        T -= i;
    }
}

int main()
{
    cin >> k >> n;
    result[0] = 1;
    Try(1);
    return 0;
}
