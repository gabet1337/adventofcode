#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
  set<string> names;
  map<pair<string,string>, int> happiness;
  string name1,name2,factor,x;
  int h;
  string me = "me";
  names.insert("me");
  while (cin >> name1 >> x >> factor >> h >> x >> x >> x >> x >> x >> x >> name2) {
    name2.pop_back();
    cout << name1 << " " << name2 << " " << factor << " " << h << endl;
    happiness[{name1,name2}] = (factor == "gain" ? h : -1*h);
    happiness[{me, name1}] = 0;
    happiness[{me, name2}] = 0;
    happiness[{name1, me}] = 0;
    happiness[{name2, me}] = 0;
    names.insert(name1);
    names.insert(name2);
  }
  vector<string> perm(names.begin(), names.end());
  sort(perm.begin(), perm.end());
  int best = 0;
  do {
    int temp = 0;
    for (int i = 1; i < perm.size()-1; i++) {
      temp += happiness[{perm[i],perm[i+1]}];
      temp += happiness[{perm[i],perm[i-1]}];
    }
    temp += happiness[{perm[0], perm[1]}];
    temp += happiness[{perm[0], perm[perm.size()-1]}];
    temp += happiness[{perm[perm.size()-1], perm[0]}];
    temp += happiness[{perm[perm.size()-1], perm[perm.size()-2]}];
    best = max(temp,best);
  } while (next_permutation(perm.begin(), perm.end()));
  cout << best << endl;
  return 0;
}
