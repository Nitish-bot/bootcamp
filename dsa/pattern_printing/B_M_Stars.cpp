#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = n; i > 0; i--) {
    for (int j = m; j > 0; j--) {
      cout << "*";
    }
    cout << endl;
  }
}