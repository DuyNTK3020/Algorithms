/*
Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu

    Dòng 1: ghi n và M (1 <= n, M <= 1000000)
    Dòng 2: ghi a1, a2, ..., an

Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, M;
    int count = 0;
    cin >> n >> M;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (binary_search(a + i + 1, a + n, M - a[i]))
            count++;
    }
    cout << count << endl;
    return 0;
}