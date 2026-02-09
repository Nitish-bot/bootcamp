#include <iostream>
using namespace std;

void print_fac2(int i) {
  int c = i;
  while(c > 0) {
    if (i % c == 0) cout << c << " ";
    c--;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  print_fac2(n);
}