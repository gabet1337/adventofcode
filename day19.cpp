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


typedef pair<string,string> ss;
int main() {

  string left,right;

  while (cin >> left >> right >> right) trans.push_back({left, right});
  sort(trans.begin(), trans.end());
  reverse(trans.begin(), trans.end());
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
