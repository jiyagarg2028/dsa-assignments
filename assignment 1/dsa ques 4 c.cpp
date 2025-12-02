#include <iostream>
using namespace std;

void transposeMatrix(int A[10][10], int transpose[10][10], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = A[i][j];
}

int main() {
    int A[10][10], transpose[10][10];
    int m, n;

    cout << "Enter rows and columns of matrix: ";
    cin >> m >> n;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    transposeMatrix(A, transpose, m, n);

    cout << "Transpose of matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}