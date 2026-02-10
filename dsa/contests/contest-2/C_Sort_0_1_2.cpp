#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int c_0 = 0;
  int c_1 = 0;
  int c_2 = 0;

  for (int i = 0; i < len; i++) {
    if (m[i] == 0) {
      c_0 += 1;
    } else if (m[i] == 1) {
      c_1 += 1;
    } else {
      c_2 += 1;
    }
  }

  for (int i = 0; i < c_2; i++) {
    cout << 2 << " ";
  }
  for (int i = 0; i < c_1; i++) {
    cout << 1 << " ";
  }
  for (int i = 0; i < c_0; i++) {
    cout << 0 << " ";
  }
  cout << endl;
}