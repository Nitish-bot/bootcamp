#include <iostream>
using namespace std;

int main() {
  string s = "*";
  for (int i = 5; i > 0; i--) {
    cout << "*";
  }

  cout << endl;

  for (int i = 4; i > 1; i--) {
    for (int j = i - 1; j > 0; j--) {
      cout << " ";
    }
    cout << s << endl;   
  }

  for (int i = 5; i > 0; i--) {
    cout << "*";
  }
}