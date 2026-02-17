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

  bool top_to_bottom = true;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (top_to_bottom) {
        cout << arr[j][i];
      } else {
        cout << arr[n - j - 1][i];
      }
      cout << " ";
    }
    top_to_bottom = !top_to_bottom;
  }
  cout << endl;
}