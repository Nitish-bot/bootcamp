#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int len = s.size();

  bool strong = true;
  if (len != 10) {
    strong = false;
  } else {
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;
    for (int i = 0; i < len; i++) {
      int ascii = (int)s[i];
      if (ascii > 47 && ascii <= 57) {
        has_digit = true;
      } else if (ascii > 64 && ascii <= 90) {
        has_upper = true;
      } else if (ascii > 96 && ascii <= 122) {
        has_lower = true;
      } else {
        has_special = true;
      }
    }
    if (!has_digit || !has_lower || !has_upper || !has_special) {
      strong = false;
    }
  }

  if (strong) {
    cout << "Strong";
  } else {
    cout << "Weak";
  }
  cout << endl;
}