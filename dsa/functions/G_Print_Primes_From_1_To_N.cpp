#include <iostream>
using namespace std;

bool isPrime(int i) {
  if (i == 1) return false;
  bool prime = true;
  for (int j = 2; j < i; j++) {
    if (i % j == 0) {
      prime = false;
      break;
    }
  }
  return prime;
}

void print_primes(int n) {
  for (int i = 1; i <= n; i++) {
    if (isPrime(i)) {
      cout << i << " ";
    }
  }
  cout << endl;
}

int main() {
  int i;
  cin >> i;

  print_primes(i);
}