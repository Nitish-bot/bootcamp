#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int direction = 1;
  int row = 0;
  while (row >= 0) {
    for (int i = 0; i < row; i++) {
      cout << " ";
    }
    cout << ">";

    if (row != 0) {
      for (int j = 0; j < 2 * row - 1; j++) {
        cout << " ";
      }
      cout << ">"; 
    }

    cout << endl;

    if (row == n - 1) {
      direction *= -1;
    }
    row += direction;
  }

}