#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

  long long vals[5][4];
  string skip;
  long long cap,dur,flav,tex,cal;
  int idx = 0;
  while (cin >> skip >> skip >> cap >> skip >> skip >> dur >> skip >> skip >>
	 flav >> skip >> skip >> tex >> skip >> skip >> cal) {
    cout << cap << " " << dur << " " << flav << " " << tex << " " << cal << endl;
    vals[0][idx] = cap;
    vals[1][idx] = dur;
    vals[2][idx] = flav;
    vals[3][idx] = tex;
    vals[4][idx] = cal;
    idx++;
  }
  long long zero = 0;
  long long best = 0;
  for (long long i = 0; i <= 100; i++) {
    for (long long j = 0; j <= 100; j++) {
      if (i+j > 100) break;
      for (long long k = 0; k <= 100; k++) {
	if (i+j+k > 100) break;
	for (long long p = 0; p <= 100; p++) {
	  if (i+j+k+p != 100) continue;
	  long long tcal = i*vals[4][0] + j*vals[4][1] + k*vals[4][2] + p*vals[4][3];
	  if (tcal != 500) continue;
	  long long tcap = i*vals[0][0] + j*vals[0][1] + k*vals[0][2] + p*vals[0][3];
	  long long tdur = i*vals[1][0] + j*vals[1][1] + k*vals[1][2] + p*vals[1][3];
	  long long tflav = i*vals[2][0] + j*vals[2][1] + k*vals[2][2] + p*vals[2][3];
	  long long ttex = i*vals[3][0] + j*vals[3][1] + k*vals[3][2] + p*vals[3][3];
	  long long score = max(tcap,0LL) * max(tdur,0LL) * max(tflav,0LL) * max(ttex,0LL);
	  best = max(score, best);
	}
      }
    }
  }
  cout << best << endl;
  return 0;
}
