#include <iostream>
#include <string>

using namespace std;

bool nice(string s) {
  int vowels = 0;
  for (int i = 0; i < (int)s.size(); i++)
    if (s[i] == 'a'||s[i] == 'e'||s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      vowels++;
  if (vowels < 3) return false;
  bool good = false;
  for (int i = 0; i < (int)s.size()-1; i++) {
    if (s[i] == s[i+1]) {good=true; break;}
  }
  if (!good) return false;
  for (int i = 0; i < (int)s.size()-1; i++) {
    if (s[i] == 'a' && s[i+1] == 'b') return false;
    if (s[i] == 'c' && s[i+1] == 'd') return false;
    if (s[i] == 'p' && s[i+1] == 'q') return false;
    if (s[i] == 'x' && s[i+1] == 'y') return false;
  }
  return true;
}

bool nice2(string s) {
  int good = false;
  for (int i = 0; i < (int)s.size()-2; i++) {
    if (s[i] == s[i+2]) { good = true; break; }
  }
  if (!good) return false;

  for (int i = 0; i < (int)s.size()-1; i++) {
    for (int j = i+2; j < s.size()-1; j++) {
      if (s[i] == s[j] && s[i+1]==s[j+1]) return true;
    }
  }
  return false;
}

int main() {
  string s;
  int res = 0;
  while (cin >> s) {
    if (nice2(s)) res++;
  }
  cout << res << endl;
  return 0;
}
