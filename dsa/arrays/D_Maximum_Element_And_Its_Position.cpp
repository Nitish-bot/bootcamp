#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int max = m[0];
  int index = 1;
  for (int i = 0; i < len; i++) {
    if (m[i] > max) {
      max = m[i];
      index = i + 1;
    }
  }

  cout << max << " " << index << endl;
}