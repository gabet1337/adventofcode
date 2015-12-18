#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
  vector<int> in;
  int x;
  while (cin >> x) in.push_back(x);
  int res = 0;
  int count[20];
  for (int i = 0; i < 20; i++) count[i] = 0;
  for (int i = 0; i < 1048576; i++) {
    bitset<20> bs(i);
    int sum = 0;
    for (int j = 0; j < 20; j++) if (bs[j]) sum+=in[j];
    if (sum == 150) {res++; count[bs.count()]++;}
  }
  cout << res << endl;
  for (int i = 0; i < 20; i++) if (count[i] != 0) { cout << count[i] << endl; break;}
  return 0;
}
