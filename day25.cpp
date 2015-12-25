#include <iostream>
#include <string>

using namespace std;

// int target_r = 3010, target_c = 3019;

int rec(int target_r, int target_c) {
  int r = 0, c = 0, index = 1, next = 1;
  while (!(target_r == r && target_c == c)) {
    if (r == 0) { r = next; c = 0; next++;}
    else { r--; c++;}
    index++;
  }
  return index;
  // if (r == target_r && c == target_c) return index;
  // if (r == 0) { r = next++; c = 0;}
  // else { r--; c++;}
  // return rec(r,c,index+1,next);   
}

int main() {

  
  cout << rec(3-1,3-1) << endl;
  cout << rec(3010-1,3019-1) << endl;
  int end = rec(3010-1, 3019-1);
  // int end = 6;
  //int end = 3;
  long long start = 20151125;
  for (int i = 1; i < end; i++) {
    start = (start*252533LL)%33554393LL;
  }

  cout << start << endl;

  // RecursiveCantor(0,0,1,0);
  return 0;
}
