// ncr aale
#include <iostream>
using namespace std;

long long factorial(int i) {
  long long fac = 1;
  for (long long j = 2; j <= i; j++){
    fac *= j;
  }
  return fac;
}

long long bin(int n, int r) {
  int fac_n = factorial(n);
  int fac_r = factorial(r);
  int fac_diff = factorial(n - r);
  return fac_n / (fac_r * fac_diff);
}

int main() {
  int i, j;
  cin >> i >> j;

  cout << bin(i, j) << endl;
}