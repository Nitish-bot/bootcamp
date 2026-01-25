#include <iostream>
using namespace std;

int main() {
  int n = 10;

  for (int i = 1; i < n + 1; i++) {
    int res = 5 * i;
    cout << "5 * " << i << " = ";
    cout << to_string(res) << endl;
  }
}