#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = n; i > 0; i--) {
    for (int j = n; j > 0; j--) {
      if (i == n || i == 1 || j == n || j == 1) {
        cout << "*";
        continue;
      }
      cout << " ";
    }
    cout << endl;
  }
}