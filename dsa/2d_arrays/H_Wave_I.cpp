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

  bool left_to_right = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (left_to_right) {
        cout << arr[i][j];
      } else {
        cout << arr[i][m - j - 1];
      }
      cout << " ";
    }
    left_to_right = !left_to_right;
  }
  cout << endl;
}