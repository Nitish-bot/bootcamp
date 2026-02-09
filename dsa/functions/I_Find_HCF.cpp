#include <iostream>
using namespace std;

int find_hcf(int lower, int higher) {
  int hcf = 1;
  for (int i = 1; i <= lower; i++) {
    if (lower % i == 0 && higher % i == 0) {
      hcf = i;
    }
  }
  return hcf;
}

int main() {
  int a, b;
  cin >> a >> b;

  if (a < b) {
    cout << find_hcf(a, b) << endl;
  } else {
    cout << find_hcf(b, a) << endl;
  }
}
