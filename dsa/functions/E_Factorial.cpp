#include <iostream>
using namespace std;

long long factorial(int i) {
  long long fac = 1;
  for (long long j = 2; j <= i; j++){
    fac *= j;
  }
  return fac;
}

int main() {
  int n;
  cin >> n;

  cout << factorial(n) << endl;
}