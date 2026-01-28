#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int cols = n * 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < cols; j++) {
      if (j <= i || j >= cols - i - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}
