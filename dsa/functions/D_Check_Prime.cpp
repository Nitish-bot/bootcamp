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

int main() {
  int n;
  cin >> n;

  bool prime = isPrime(n);
  if (prime) {
    cout << "Prime";
  } else {
    cout << "Not Prime";
  }
  cout << endl;
}