#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int row = 1;
  
  while (row < n) {
    for (int i = 0; i < row; i++) {
      cout << "*" << " ";
    }
    cout << endl;
    row++;
  }

  while (row > 0) {
    for (int i = 0; i < row; i++) {
      cout << "*" << " ";
    }
    cout << endl;
    row--;
  }
}