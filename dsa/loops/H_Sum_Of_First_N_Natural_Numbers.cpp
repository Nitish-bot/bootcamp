#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long sum = 0;
  for (int i = 1; i < n + 1; i++) {
    sum += i;
  }

  cout << sum << endl;
}