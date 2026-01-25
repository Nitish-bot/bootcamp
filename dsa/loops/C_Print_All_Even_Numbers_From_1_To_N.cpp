#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  for (int i = 2; i < a + 1; i += 2) {
    cout << i << " ";
  }
  cout << endl;
}