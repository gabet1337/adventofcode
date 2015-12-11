#include <iostream>
#include <string>
using namespace std;

void next(string &s) {
  for (int i = s.size()-1; i >= 0; i--) {
    if (s[i] == 'z') s[i] = 'a';
    else {s[i]++; break;}
  }
}

bool check(string &s) {
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'i' || s[i] == 'o' || s[i] == 'l') return false;
  bool good = false;
  for (int i = 0; i < s.size()-3; i++) {
    if (s[i] == s[i+1]-1 && s[i+1] == s[i+2]-1) { good = true; break;}
  }
  if (!good) return false;
  for (int i = 0; i < s.size()-1; i++) {
    if (s[i] == s[i+1]) {
      for (int j = i+2; j < s.size()-1; j++) {
	if (s[j] == s[j+1]) { return true;}
      }
    }
  }
  return false;
}

int main() {

  string s = "cqjxjnds";
  while (!check(s)) next(s);
  cout << s << endl;

  string s2 = "cqjxxyzz";
  next(s2);
  while (!check(s2)) next(s2);
  cout << s2 << endl;


  return 0;
}
