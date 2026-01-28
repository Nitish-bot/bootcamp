#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = n; i > 0; i--) {
    for (int j = 0; j < n - i; j++) {
      cout << " ";
    }

    for (int k = 0; k < i; k++) {
      if (k == 0 || k == i - 1 || i == n) {
        cout << "*";
      } else {
        cout << " ";
      }

      if (k != i - 1) cout << " ";
    }

    cout << endl;
  }
}