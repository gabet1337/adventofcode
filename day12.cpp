#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {

  string s;
  cin >> s;
  string buffer;
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
      while (i < s.size()) {
	if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-')) break;
	buffer+=s[i];
	i++;
      }
      // cout << buffer << endl;
      res += atoi(buffer.c_str());
      buffer = "";
    }
  }
  cout << res << endl;

  return 0;
}
