#include <iostream>
using namespace std;

void printMinMax(int min, int max) {
  cout << "Min = " << min << endl;
  cout << "Max = " << max << endl;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a >= b && a >= c) {
    if (b >= c) {
      printMinMax(c, a);
    } else {
      printMinMax(b, a);
    }
  } else if (b >= c && b >= a) {
    if (c >= a) {
      printMinMax(a, b);
    } else {
      printMinMax(c, b);
    }
  } else {
    if (a >= b) {
      printMinMax(b, c);
    } else {
      printMinMax(a, c);
    }
  }
}