#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int,pair<int,int> > iii;
int main() {

  int speed,time,rest;
  vector<int> points,distance,tt;
  vector<iii> reindeer;
  string skip;
  while (cin >> skip >> skip >> skip >> speed >> skip >> skip >> time >>
	 skip >> skip >> skip >> skip >> skip >> skip >> rest >> skip) {
    reindeer.push_back({speed,{time,rest}});
    points.push_back(0);
    distance.push_back(0);
    tt.push_back(time);
  }

  vector<bool> do_rest(reindeer.size(), false);

  for (int i = 0; i < 2503; i++) {
    for (int j = 0; j < reindeer.size(); j++) {
      //move the j'th reindeer
      if (i == tt[j]) {
	if (do_rest[j]) {
	  tt[j] += reindeer[j].second.first;
	  do_rest[j] = false;
	} else {
	  tt[j] += reindeer[j].second.second;
	  do_rest[j] = true;
	}
      }
      if (!do_rest[j]) distance[j] += reindeer[j].first;
    }

    //see who is in front
    int f = distance[0];
    for (int j = 0; j < distance.size(); j++) {
      cout << distance[j] << " ";
      f = max(f,distance[j]);
    }
    cout << endl;
    for (int j = 0; j < distance.size(); j++) {
      if (distance[j] == f) points[j]++;
    }
  }
  for (int i = 0; i < points.size(); i++) {
    cout << points[i] << endl;
  }
  return 0;
}
