#include <iostream>
#include <string>
using namespace std;

int main() {
  string instr;
  cin >> instr;
  int floor = 0;
  for (int i = 0; i < (int)instr.size(); i++) {
    if (instr[i] == '(') floor++;
    else floor--;
    if (floor == -1) {
      cout << "entering -1 at " << i+1 << endl;
    }

  }
  cout << floor << endl;
  return 0;
}
