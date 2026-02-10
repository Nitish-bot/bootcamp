// lol be real
#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int curr = len / 2 - 1;
  int next = len / 2;

  while (curr >= 0) {
    cout << m[curr] << " " << m[next] << " ";
    curr -= 1;
    next += 1;
  }
  cout << endl;
}