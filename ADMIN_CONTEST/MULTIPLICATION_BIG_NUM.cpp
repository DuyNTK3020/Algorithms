/*
Description
Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
Input

    Dòng 1: ghi số a
    Dòng 2: ghi số b

Output

    Ghi kết quả a*b


Example
Input
123
654

Output
80442

Example
Input
100000000000000000
123456789
Output
12345678900000000000000000
*/

#include <bits/stdc++.h>

using namespace std;

// Hàm nhân hai số lớn
string multiply(string num1, string num2)
{
    int m = num1.size();
    int n = num2.size();
    vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Bỏ các số 0 ở đầu kết quả
    auto it = find_if(result.begin(), result.end(), [](int digit)
                      { return digit != 0; });

    string multiplication = "";
    for (; it != result.end(); ++it)
    {
        multiplication += to_string(*it);
    }

    // Trường hợp nếu kết quả là chuỗi rỗng, tức là a * b = 0
    if (multiplication.empty())
    {
        return "0";
    }

    return multiplication;
}

int main()
{
    string a, b;

    // Nhập số a
    cin >> a;

    // Nhập số b
    cin >> b;

    // Tính và in ra kết quả a * b
    string result = multiply(a, b);
    cout << result << endl;

    return 0;
}
