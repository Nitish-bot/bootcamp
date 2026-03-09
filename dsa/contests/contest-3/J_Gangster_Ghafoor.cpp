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

  int start_col = 0;
  int end_col = n - 1;
  int start_row = 0;
  int end_row = m - 1;

  for (int i = end_row; i >= start_row; i--) {
    int check = arr[i][start_col];
    if (check == -1) {
      return 0;
    }
    cout << check << " ";
  }
  start_col++;

  for (int i = start_col; i <= end_col; i++) {
    int check = arr[start_row][i];
    if (check == -1) {
      return 0;
    }
    cout << check << " ";
  }
  start_row++;

  for (int i = start_row; i <= end_row; i++) {
    int check = arr[i][end_col];
    if (check == -1) {
      return 0;
    }
    cout << check << " ";
  }
  end_col--;

  for (int i = end_col; i >= start_col; i--) {
    int check = arr[end_row][i];
    if (check == -1) {
      return 0;
    }
    cout << check << " ";
  }
  end_row--;

  cout << endl;
}
