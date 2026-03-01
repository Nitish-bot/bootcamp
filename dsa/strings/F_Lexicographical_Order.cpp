#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  if (a < b) {
    cout << "A";
  } else if (a == b) {
    cout << "Equal";
  } else {
    cout << "B";
  }
  cout << endl;
}