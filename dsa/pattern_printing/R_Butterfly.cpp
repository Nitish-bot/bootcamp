#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int direction = 1;
  int cols = n * 2;
  int row = 1;
  while (row > 0) {
    for (int i = 1; i < cols + 1; i++) {
      if (i <= row || i > cols - row) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
    
    if (row == n) {
      direction *= -1;
    }
    row += direction;
  }
}