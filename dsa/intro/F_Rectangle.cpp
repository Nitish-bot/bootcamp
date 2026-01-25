#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  int a, b;

  cin >> a >> b;
  
  int area = a * b;
  int perimeter = 2 * (a + b);

  cout << "Area = " << area << endl;
  cout << "Perimeter = " << perimeter << endl;
}