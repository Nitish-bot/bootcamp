#include <iostream>
using namespace std;

void printMinMax(int min, int max) {
  cout << "Min = " << min << endl;
  cout << "Max = " << max << endl;
}

int main() {
  int a, b;
  cin >> a >> b;

  if (a < b) {
    printMinMax(a, b);
  } else {
    printMinMax(b, a);
  }
}
