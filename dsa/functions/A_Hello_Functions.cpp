#include <iostream>
using namespace std;

void printl(int t) {
  while(t > 0) {
    t--;
    cout << "I am learning functions" << endl;
  }
}

int main() {
  int n;
  cin >> n;

  printl(n);
}