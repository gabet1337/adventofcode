#include <iostream>
#include <string>
using namespace std;

int nl(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '"') res++;
    else if (s[i] == '\\') res++;
    res++;
  }
  return res;
}

int ec(string s) {
  int res = 0;
  for (int i = 1; i < s.size()-1; i++) {
    if (s[i] == '\\' && s[i+1] == 'x') { i+=3; res++;}
    else if (s[i] == '\\' && s[i+1] == '\\') { i++; res++;}
    else if (s[i] == '\\' && s[i+1] == '"') { i++; res++;}
    else res++;
  }
  return res;
}

int main() {

  string s;
  int res = 0;
  int res2 = 0;
  while (cin >> s) {
    cout << s << endl;
    cout << nl(s) << endl;
    res += s.size() - ec(s);
    res2 += (nl(s)+2) - s.size();
  }
  cout << res << endl;
  cout << res2 << endl;
  return 0;
}
