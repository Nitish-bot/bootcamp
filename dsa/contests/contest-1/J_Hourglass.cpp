#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int direction = 1;
  int row = 1;
  while (row > 0) {
    for (int i = 1; i < row; i++) {
      cout << " ";
    }

    for (int j = 0; j < n - row + 1; j++) {
      cout << ".";
      if (j != n - row) cout << " ";
    }

    cout << endl;

    if (row == n) {
      direction *= -1;
    }
    row += direction;
  }
}