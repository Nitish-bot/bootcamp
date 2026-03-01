#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  int n = s.size();

  int words = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      if (i != n - 1) {
        words++;
      }
    }
  }

  cout << words << endl;
}