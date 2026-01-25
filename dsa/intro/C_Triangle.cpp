#include <iostream>
using namespace std;

int main() {
  string s = "*";

  for (int i = 5; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      cout << s;
    }
    cout << endl;
  };
}