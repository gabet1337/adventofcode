#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {

  map<pair<string,string>, int> distances;
  string c1,c2,x;
  int d;
  set<string> s;
  while (cin >> c1 >> x >> c2 >> x >> d) {
    distances[{c1,c2}] = d;
    distances[{c2,c1}] = d;
    s.insert(c1);
    s.insert(c2);
  }
  vector<string> vs(s.begin(), s.end());
  sort(vs.begin(), vs.end());
  int shortest = 1000000000;
  int longest = 0;
  do {
    int temp = 0;
    for (int i = 0; i < vs.size()-1; i++) {
      temp += distances[{vs[i],vs[i+1]}];
    }
    shortest = min(temp,shortest);
    longest = max(temp,longest);
  } while (next_permutation(vs.begin(), vs.end()));
  cout << shortest << endl;
  cout << longest << endl;
  return 0;
}
