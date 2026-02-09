#include <iostream>
using namespace std;

void printfac(int i) {
  int c = 2;
  cout << 1 << " ";
  while (c <= i) {
    if (i % c == 0) {
      cout << c << " ";
    }
    c++;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  printfac(n);
}