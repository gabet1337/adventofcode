#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

// children: 3
// cats: 7
// samoyeds: 2
// pomeranians: 3
// akitas: 0
// vizslas: 0
// goldfish: 5
// trees: 3
// cars: 2
// perfumes: 1


int main() {
  string skip;
  string key;
  int val;
  vector<map<string,int> > kl(500,map<string,int>());

  vector<int> possible;
  for (int i = 0; i < 500; i++) possible.push_back(i);
  for (int i = 0; i < 500; i++) {
    cin >> skip >> skip >> key >> val >> skip;
    key.pop_back();
    kl[i][key] = val;
    cin >> key >> val >> skip;
    key.pop_back();
    kl[i][key] = val;
    cin >> key >> val;
    key.pop_back();
    kl[i][key] = val;
    // for (auto x : kl[i]) cout << x.first << " " << x.second << endl;
  }
  map<string,int> w;
  w["children"] = 3;
  w["cats"] = 7;
  w["samoyeds"] = 2;
  w["pomeranians"] = 3;
  w["akitas"] = 0;
  w["vizslas"] = 0;
  w["goldfish"] = 5;
  w["trees"] = 3;
  w["cars"] = 2;
  w["perfumes"] = 1;

  for (int i = 0; i < 500; i++) {
    bool pos = true;
    for (auto x : kl[i]) {
      if (x.first == "cats" || x.first == "trees") {
	if (w[x.first] < x.second) continue;
	else pos = false;
	break;
      } else if (x.first == "pomeranians" || x.first == "goldfish") {
	if (w[x.first] > x.second) continue;
	else pos = false;
	break;
      } else if (w[x.first] == x.second) continue;
      else {
	pos = false;
	break;
      }
    }
    if (pos) cout << i+1 << endl;

  }


  return 0;
}
