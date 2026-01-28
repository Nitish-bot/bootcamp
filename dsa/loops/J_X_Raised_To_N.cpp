#include <iostream>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;

  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  long long x_n = x;
  for (int i = 1; i < n; i++) {
    x_n *= x;
  }
  cout << x_n << endl;
}