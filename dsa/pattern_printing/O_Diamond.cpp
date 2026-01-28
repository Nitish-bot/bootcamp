#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int row = 1;
  int direction = 1;
  while (row > 0) {
    for (int j = 0; j < n - row; j++) {
      cout << " ";
    }

    for (int k = 0; k < row; k++) {
      cout << "*";
      if (k != row) cout << " ";
    }

    cout << endl;

    if (row == n) {
      direction *= -1;
    }
    row += direction;
  }
}