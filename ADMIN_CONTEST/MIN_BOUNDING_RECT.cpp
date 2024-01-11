/*
Description
Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên
Dữ liệu
· Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
· Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
Kết quả
· Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
Ví dụ
Dữ liệu
3
2 4 2 7
3 2 4 7
1 2 5 2
Kết quả
20
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int xmin = INT_MAX;
    int xmax = INT_MIN;
    int ymin = INT_MAX;
    int ymax = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xmin = min(xmin, x1);
        xmin = min(xmin, x2);
        ymin = min(ymin, y1);
        ymin = min(ymin, y2);
        xmax = max(xmax, x1);
        xmax = max(xmax, x2);
        ymax = max(ymax, y1);
        ymax = max(ymax, y2);
    }
    cout << (xmax - xmin) * (ymax - ymin);
    return 0;
}