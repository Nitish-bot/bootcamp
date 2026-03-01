#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  bool pal = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      pal = false;
      break;
    }
  }
  if (pal) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}