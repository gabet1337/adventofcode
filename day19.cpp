#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<string,string> ss;
set<string> current;
set<string> step;
//string input = "HOHOHO";
string input = "CRnCaCaCaSiRnBPTiMgArSiRnSiRnMgArSiRnCaFArTiTiBSiThFYCaFArCaCaSiThCaPBSiThSiThCaCaPTiRnPBSiThRnFArArCaCaSiThCaSiThSiRnMgArCaPTiBPRnFArSiThCaSiRnFArBCaSiRnCaPRnFArPMgYCaFArCaPTiTiTiBPBSiThCaPTiBPBSiRnFArBPBSiRnCaFArBPRnSiRnFArRnSiRnBFArCaFArCaCaCaSiThSiThCaCaPBPTiTiRnFArCaPTiBSiAlArPBCaCaCaCaCaSiRnMgArCaSiThFArThCaSiThCaSiRnCaFYCaSiRnFYFArFArCaSiRnFYFArCaSiRnBPMgArSiThPRnFArCaSiRnFArTiRnSiRnFYFArCaSiRnBFArCaSiRnTiMgArSiThCaSiThCaFArPRnFArSiRnFArTiTiTiTiBCaCaSiRnCaCaFYFArSiThCaPTiBPTiBCaSiThSiRnMgArCaF";

vector<ss> trans;

void take_step() {
  step.clear();
  for (string s : current) {
    for (ss t : trans) {
      for (int i = 0; i < s.size()-t.first.size()+1; i++) {
	bool match = true;
	for (int j = 0; j < t.first.size(); j++)
	  if (s[i+j] != t.first[j]) { match = false; break;}
	if (match) {
	  step.insert(s.substr(0,i) + t.second + s.substr(i+t.first.size()));
	}
      }
    }
  }
  swap(current,step);
}

bool search_replace(int i) {
  size_t found = input.find(trans[i].second);
  if (found != string::npos) {
    input.replace(found, trans[i].second.size(), trans[i].first);
    cout << "replaced " << trans[i].second << " with " << trans[i].first << endl;
    return true;
  }
  return false;
}


typedef pair<string,string> ss;
int main() {

  string left,right;

  while (cin >> left >> right >> right) trans.push_back({left, right});
  sort(trans.begin(), trans.end());
  // reverse(trans.begin(), trans.end());
  int res = 0;
  while (input != "e") {
    for (int i = 0; !search_replace(i); i++);
    res++;
  }
  cout << res << endl;
  return 0;
  
  int result = 0;
  current.insert("e");
  while (current.find(input) == current.end()) {
    cout << result << endl;
    take_step();
    result++;
  }
  cout << result << endl;
  return 0;
}
