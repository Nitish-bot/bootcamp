#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  long long sum = 0;
  for (int i = 0; i < len; i++) {
    cin >> m[i];
    sum += m[i];
  }

  cout << sum << endl;
}