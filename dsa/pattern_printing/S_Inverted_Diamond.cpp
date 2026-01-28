#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int direction = 1;
  int cols = n * 2 + 1;
  int row = 1;
  while (row > 0) {
    for (int i = 0; i < cols; i++) {
      if (i > n - row && i < n + row) {
        cout << " ";
      } else {
        cout << "*";
      }
    }
    cout << endl;

    if (row == n) {
      direction *= -1;
    }
    row += direction;
  }
}