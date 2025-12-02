#include <iostream>
using namespace std;

void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10], int m, int n, int p) {
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            result[i][j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int m, n, p;
    cout << "Enter rows and columns of first matrix (m n): ";
    cin >> m >> n;
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter columns of second matrix (p): ";
    cin >> p;
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    multiplyMatrices(A, B, result, m, n, p);
    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}