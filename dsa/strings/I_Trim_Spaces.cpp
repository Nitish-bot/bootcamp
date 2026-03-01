#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      continue;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}