#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int arr[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j]; 
    }
  }

  int start_row = 0;
  int end_row = m - 1;
  int start_col = 0;
  int end_col = n - 1;
  while (start_row <= end_row && start_col <= end_col) {
    for (int i = start_col; i <= end_col; i++) {
      cout << arr[start_row][i] << " ";
    }
    start_row++;

    for (int i = start_row; i <= end_row; i++) {
      cout << arr[i][end_col] << " ";
    }
    end_col--;

    if (start_row <= end_row && start_col <= end_col) {
      for (int i = end_col; i >= start_col; i--) {
        cout << arr[end_row][i] << " ";
      }
      end_row--;
  
      for (int i = end_row; i >= start_row; i--) {
        cout << arr[i][start_col] << " ";
      }
      start_col++;
    }
  }
}