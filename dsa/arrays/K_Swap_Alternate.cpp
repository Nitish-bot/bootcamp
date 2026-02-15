#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int m[n];
  bool prev = false;
  for (int i = 0; i < n; i++) {
    if (n % 2 == 1 && i == n - 1) {
      cin >> m[i];
    } else if (prev) {
      cin >> m[i - 1];
    } else {
      cin >> m[i + 1];
    }
    prev = !prev;
  }

  for (int i = 0; i < n; i++) {
    cout << m[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}