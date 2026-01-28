#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int direction = 1;
  int row = 1;
  while (row > 0) {
    for (int i = 0; i < row; i++) {
      if (i == 0 || i == row - 1) {
        cout << "*";
      }
      cout << " ";
    }
    cout << endl;

    if (row == n) {
      direction *= -1;
    }

    row += direction;
  }
}