#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <set>
using namespace std;

int main() {
  map<string,vector<string> > mvs;
  map<string, int> values;
  map<string,string> ops;
  set<string> states;
  string line;
  int nextid = 1;
  while (getline(cin, line)) {
    istringstream ss(line);
    string first;
    string u,v;
    string dest;
    ss >> first;
    if (first == "NOT") {
      ss >> u;
      ss >> v >> v;
      cout << "NOT " << u << " -> " << v << endl;
      ops[v] = "NOT";
      mvs[v].push_back(u);
      values[v] = -1;
      states.insert(u);
      states.insert(v);
    } else if (first[0] >= '0' && first[0] <= '9') {
      ss >> u;
      if (u == "->") {
	ss >> u;
	cout << first << " -> " << u << endl;
	mvs[u].push_back(first);
	values[u] = atoi(first.c_str());
	states.insert(u);
	states.insert(first);
      } else {
	if (u == "AND") {
	  u = first;
	  ss >> v;
	  ss >> dest >> dest;
	  cout << u << " AND " << v << " -> " << dest << endl;
	  values[dest] = -1;
	  mvs[dest].push_back(u);
	  values[u] = atoi(u.c_str());
	  mvs[dest].push_back(v);
	  ops[dest] = "AND";
	  states.insert(u);
	  states.insert(v);
	  states.insert(dest);
	}
      }
    } else {
      u = first;
      ss >> first;
      ss >> v;
      if (first == "->") {
	cout << u << " -> " << v << endl;
	mvs[v].push_back(u);
	values[v] = -1;
	states.insert(u);
	states.insert(v);
	ops[v] = "ASSIGN";
	continue;
      }
      ss >> dest >> dest;
      ops[dest] = first;
      if (first == "LSHIFT" || first == "RSHIFT")
	values[v] = atoi(v.c_str());
      mvs[dest].push_back(u);
      mvs[dest].push_back(v);
      values[dest] = -1;
      cout << u << " " << first << " " << v << " -> " << dest << endl;
      states.insert(u);
      states.insert(v);
      states.insert(dest);
    }
  }
  values["b"] = 3176;
  for (int i = 0; i < 10000; i++) {
    for (auto x : states) {
      if (x.empty()) continue;
      if (values[x] != -1) continue;
      bool good = true;
      for (auto y : mvs[x]) {
	if (values[y] == -1) { good = false; break;}
      }
      if (good) {
	if (ops[x].empty()) continue;
	if (ops[x] == "ASSIGN") {
	  cout << "ASSIGN " << values[mvs[x][0]] << endl;
	  values[x] = values[mvs[x][0]];
	}
	else if (ops[x] == "NOT") {
	  cout << "NOT " << values[mvs[x][0]] << endl;
	  values[x] = (~(values[mvs[x][0]])&0xFFFF);
	}
	else if (ops[x] == "AND") {
	  cout << mvs[x][0] << " AND " << mvs[x][1] << endl;
	  cout << values[mvs[x][0]] << " AND " << values[mvs[x][1]] << endl;
	  values[x] = (values[mvs[x][0]] & values[mvs[x][1]]);
	}
	else if (ops[x] == "OR") {
	  cout << mvs[x][0] << " OR " << mvs[x][1] << endl;
	  cout << values[mvs[x][0]] << " OR " << values[mvs[x][1]] << endl;
	  values[x] = (values[mvs[x][0]] | values[mvs[x][1]]);
	}
	else if (ops[x] == "LSHIFT") {
	  cout << mvs[x][0] << " << " << mvs[x][1] << endl;
	  cout << values[mvs[x][0]] << " << " << values[mvs[x][1]] << endl;
	  values[x] = (values[mvs[x][0]] << values[mvs[x][1]])&0xFFFF;
	}
	else if (ops[x] == "RSHIFT") {
	  cout << mvs[x][0] << " >> " << mvs[x][1] << endl;
	  cout << values[mvs[x][0]] << ">>" << values[mvs[x][1]] << endl;
	  values[x] = (values[mvs[x][0]] >> values[mvs[x][1]])&0xFFFF;
	}
	cout << "assigned value " << values[x] << " to " << x << endl << endl;
      }
      

    }
  }
  cout << values["a"] << endl;

  return 0;
}
