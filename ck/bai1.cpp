#include <bits/stdc++.h>

using namespace std;

int Try(int arr[], int n) {
    sort(arr, arr + n); 
    int count = 0;
    for (int i = n-1; i > 1; i--) {
        int left = 0;
        int right = n - 2;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                count++;
                left++;
                right--;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = Try(arr, n);

    cout << result;

    return 0;
}