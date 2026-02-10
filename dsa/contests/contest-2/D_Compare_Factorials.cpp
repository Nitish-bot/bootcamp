#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  if (a == b) {
    cout << "Yes";
  } else {
    if (a == 0 || a == 1) {
      if (b == 0 || b == 1) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    } else {
      cout << "No";
    }
  }
  cout << endl;
}