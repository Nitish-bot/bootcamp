#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = n; i > 0; i--) {
    for (int j = m; j > 0; j--) {
      if (i == n || i == 1 || j == m || j == 1) {
        cout << "*";
        continue;
      }
      cout << " ";
    }
    cout << endl;
  }
}