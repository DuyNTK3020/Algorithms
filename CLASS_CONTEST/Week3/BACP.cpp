/*
Description
The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced. There are N courses 1, 2, …, N that must be assigned to M periods 1, 2, …, M. Each course i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period.
The prerequisites information is represented by a matrix ANxN in which Ai,j = 1 indicates that course i must be assigned to a period before the period to which the course j is assigned. Compute the solution satisfying constraints: 

    Satisfy the prerequisites constraints: if Ai,j = 1, then course i must be
    assigned to a period before the period to which the course j is assigned
    The maximum load for all periods is minimal

Input

    Line 1 contains N and M (2 ≤ N ≤16, 2 ≤ M ≤ 5)
    Line 2 contains c1, c2, …, cN
    Line i+2 (i = 1,…, N) contains the ith line of the matrix A

Output

    Unique line contains that maximum load for all periods of the solution
    found

Example
Input
6 2
4 4 4 4 2 4 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 1 0 0 0 
0 0 1 0 0 0 
1 0 0 0 0 0

Output
12
*/

#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int N, M;               // N Số môn, M số kỳ học
int C[MAX];             // Số tín chỉ mỗi môn
int A[MAX][MAX];        // Ma trận môn i bắt buộc học trước môn j
int X[MAX];      // Tập chỉ số môn học được học ở kỳ nào
int load[MAX];      // Tập chứa giá trị lớn nhất của các kỳ
int loadMax = INT_MIN;    // Giá trị lớn nhất mỗi kỳ
int loadMin = INT_MAX; // Giá trị nhỏ nhất của các max

bool check(int v, int k)
{ // Kiểm tra môn học k tại kỳ v
    for (int i = 0; i < k; i++)
    {
        if (A[i][k]) // Nếu môn i phải đăng ký trước môn k
        {
            if (X[i] >= v)
                return false; // Khi kỳ học môn i >= kỳ học môn k thì false
        }
        else if (A[k][i]) // Nếu môn k phải đăng ký trước môn i
        {
            if (v >= X[i])
                return false; // Khi kỳ học môn i <= kỳ học môn k thì false
        }
    }
    return true;
}

void Try(int k)
{
    for (int i = 0; i < M; i++)
    {
        if (check(i, k))
        {
            X[k] = i; // Môn k được học vào kỳ i
            load[i] += C[k];
            if (k == N - 1)
            {
                loadMax = INT_MIN;
                for (int i = 0; i < M; i++)
                {
                    loadMax = max(loadMax, load[i]);
                }
                loadMin = min(loadMax, loadMin);
            }
            else
                Try(k + 1);
            load[i] -= C[k];
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    Try(0);
    cout << loadMin << endl;
    return 0;
}
