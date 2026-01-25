#include <iostream>
using namespace std;

int main() {
  int start = 65;

  for (int i = start; i < start + 26; i++) {
    char c = (char)i;
    cout << c << " ";
  }
  cout << endl;
}