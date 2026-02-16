#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  int m[n];
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }

  for (int i = 0; i < n; i++) {
    int target = m[i];
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (m[j] == target) {
        count++;
      }
    }
    if (count == 1) {
      cout << target << endl;
      break;
    }
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}