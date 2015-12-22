#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int main() {
  int b_dmg = 8, b_armor = 2, b_hp = 100;

  ii weapons[5], armor[5], rings[6];
  weapons[0] = {8,4};
  weapons[1] = {10,5};
  weapons[2] = {25,6};
  weapons[3] = {40,7};
  weapons[4] = {74,8};

  armor[0] = {13,1};
  armor[1] = {31,2};
  armor[2] = {53,3};
  armor[3] = {75,4};
  armor[4] = {102,5};
  armor[5] = {0,0};

  rings[0] = {25,1};
  rings[1] = {50,2};
  rings[2] = {100,3};
  rings[3] = {20,1};
  rings[4] = {40,2};
  rings[5] = {80,3};
  rings[6] = {0,0};
  int best = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 7; k++) {
	for (int q = 0; q < 7; q++) {
	  if (q==k && q != 6) continue;
	  int p_dmg = weapons[i].second;
	  int p_armor = armor[j].second;
	  if (k < 3) p_dmg += rings[k].second;
	  else p_armor += rings[k].second;
	  if (q < 3) p_dmg += rings[q].second;
	  else p_armor += rings[q].second;
	  if (b_dmg - p_armor > p_dmg - b_armor) {
	    int total = weapons[i].first+armor[j].first+rings[k].first+rings[q].first;
	    if (best < total) {
	      cout << i << " " << j << " " << k << " " << q << endl;
	      best = max(total, best);
	    }
	  }
	}
      }
  cout << best << endl;
  return 0;
}
