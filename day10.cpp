#include <iostream>
#include <string>

using namespace std;

string step(string input) {
  string res = "";
  int count = 1;
  for (int i = 0; i < (int)input.size(); i++) {
    if (i == input.size()-1) {
      res+="1";
      res+=input[i];
    } else {
      if (input[i] == input[i+1]) count++;
      else {
	res+=(to_string(count)+input[i]);
	count = 1;
      }
    }
  }
  return res;
}

int main() {

  string start = "1321131112";
  for (int i = 0; i < 50; i++) {
    start = step(start);
  }
  cout << start.size() << endl;
    

  return 0;
}
