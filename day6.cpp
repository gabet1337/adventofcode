#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  char grid[1000][1000];
  int brightness[1000][1000];
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++) {
      grid[i][j] = 0;
      brightness[i][j] = 0;
    }

  string s;
  int x1,y1,x2,y2;
  while (cin >> s) {
    if (s == "toggle") {
      scanf("%d,%d through %d,%d\n", &x1,&y1,&x2,&y2);
      for (int i = x1; i <= x2; i++)
	for (int j = y1; j <= y2; j++) {
	  grid[i][j] = 1-grid[i][j];
	  brightness[i][j]+= 2;
	}
    } else if (s == "turn") {
      cin >> s;
      scanf("%d,%d through %d,%d\n", &x1,&y1,&x2,&y2);
      if (s == "on") {
	for (int i = x1; i <= x2; i++)
	  for (int j = y1; j <= y2; j++) {
	    grid[i][j] = 1;
	    brightness[i][j]+=1;
	  }
      } else {
	for (int i = x1; i <= x2; i++)
	  for (int j = y1; j <= y2; j++) {
	    grid[i][j] = 0;
	    brightness[i][j] = max(0, brightness[i][j]-1);
	  }
      }
    }
  }
  int res = 0;
  int bright = 0;
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++) {
      if (grid[i][j] == 1) res++;
      bright+=brightness[i][j];
    }

  cout << res << endl;
  cout << bright << endl;
  return 0;
}
