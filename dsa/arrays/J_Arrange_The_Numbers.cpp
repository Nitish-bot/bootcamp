#include <iostream>
using namespace std;

void input_arrange_output() {
  int n;
  cin >> n;

  int halfway = n / 2;
  if (n % 2 == 1) {
    halfway++;
  }

  int m[n];
  for (int i = 0; i < halfway; i++) {
    m[i] = (2 * i) + 1;
  }
  for (int i = halfway; i < n; i++) {
    m[i] = (n - i) * 2; 
  }

  for (int i = 0; i < n; i++) {
    cout << m[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    input_arrange_output();
  }
}