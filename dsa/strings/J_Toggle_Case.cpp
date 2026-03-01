#include <bits/stdc++.h>
using namespace std;

char toggle(char c) {
  int ascii = (int)c;

  if (ascii <= 90) {
    return (char)(ascii + 32);
  } else {
    return (char)(ascii - 32);
  }
}

int main() {
  string s;
  cin >> s;

  int n = s.size();

  for (int i = 0; i < n; i++) {
    cout << toggle(s[i]);
  }
  cout << endl;
}