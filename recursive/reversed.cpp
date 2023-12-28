#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];

void reverse(int start, int end) {
    if (start >= end) return;
    else {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        reverse(start + 1, end - 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}