#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int min = m[len - 1];
  int index = len;
  for (int i = len - 1; i >= 0; i--) {
    if (m[i] <= min) {
      min = m[i];
      index = i + 1;
    }
  }

  cout << min << " " << index << endl;
}