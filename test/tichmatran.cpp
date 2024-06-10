#include <iostream>
using namespace std;

int main() {
    int m1, n1, m2, n2;
    
    cout << "Nhap kich thuoc ma tran 1 (m x n): ";
    cin >> m1 >> n1;
    
    int matrix1[m1][n1];
    cout << "Nhap gia tri cho ma tran 1:\n";
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    cout << "Nhap kich thuoc ma tran 2 (m x n): ";
    cin >> m2 >> n2;
    
    if (n1 != m2) {
        cout << "Khong the nhan 2 ma tran nay!\n";
        return 0;
    }
    
    int matrix2[m2][n2];
    cout << "Nhap gia tri cho ma tran 2:\n";
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    int result[m1][n2];
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // In kết quả
    cout << "Ket qua nhan 2 ma tran:\n";
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}