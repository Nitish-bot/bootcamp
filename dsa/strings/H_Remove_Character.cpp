#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  char x;
  cin >> x;

  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == x) {
      continue;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}