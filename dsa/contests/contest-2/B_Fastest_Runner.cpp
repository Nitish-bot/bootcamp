#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int fastest = 0;
  for (int i = 0; i < len; i++) {
    if (m[i] <= m[fastest]) {
      fastest = i;
    }
  }

  cout << fastest + 1 << endl;
}