#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  bool right = true;
  if (m == 1) {
    for (int i = 0; i < n; i++) {
      cout << arr[i][0] << " ";
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0) {
          cout << arr[i][j] << " ";
        } else if (i == n - 1) {
          cout << arr[i][m - j - 1] << " ";
        } else {
          cout << arr[i][m - 1] << " ";
          break;
        }
      }
    }
    for (int i = n - 2; i > 0; i--) {
      cout << arr[i][0] << " ";
    }
  }
  cout << endl;
}