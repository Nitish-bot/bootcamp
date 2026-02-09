#include <iostream>
using namespace std;

int zero_count(long long i) {
  int zeros = 0;
  if (i == 0) {
    zeros += 1;
  } 
  while (i > 0) {
    if (i % 10 == 0) {
      zeros += 1;
    }
    i /= 10;
  }

  return zeros;
}

int main() {
  long long i;
  cin >> i;

  cout << zero_count(i) << endl;
}