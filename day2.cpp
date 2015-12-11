#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
  int l,w,h;
  long long paper = 0;
  long long ribbon = 0;
  while (scanf("%dx%dx%d\n", &l, &w, &h) == 3) {
    int sorted[3] = {l,w,h};
    sort(sorted, sorted+3);
    ribbon += sorted[0]*2 + sorted[1]*2 + l*w*h;
    paper += 2*l*w + 2*w*h + 2*h*l + min(l*w,min(w*h,h*l));
  }
  cout << paper << endl;
  cout << ribbon << endl;
}
