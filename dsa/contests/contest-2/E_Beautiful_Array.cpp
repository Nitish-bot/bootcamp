#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  bool beaut = true;
  int el = m[0];
  for (int i = 0; i < len; i++) {
    if (m[i] != el) {
      beaut = false;
      break;
    }
  }

  if (beaut) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}