#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int m[n];
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    if (m[i] == x) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}