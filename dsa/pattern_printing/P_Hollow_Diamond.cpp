#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int row = 1;
  int direction = 1;
  while (row > 0) {
    for (int i = 0; i < n - row; i++) {
      cout << " ";
    }

    for (int j = 0; j < row; j++) {
      if (j == 0 || j == row - 1) {
        cout << "*";
      } else {
        cout << " ";
      }

      if (j != row - 1) cout << " ";
    }

    cout << endl;

    if (row == n) {
      direction *= -1;
    }
    row += direction;
  }
}