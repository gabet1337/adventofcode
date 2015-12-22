#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
bitset<10000010> bs;
vi primes;
ll _sieve_size;
void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
      for (ll j = i*i; j <= _sieve_size; j+=i) bs[j] = 0;
      primes.push_back((int)i);
    }
}

int sum_of_factors(int x) {
  int res = 0;
  for (int i = 1; i < x/2+1; i++)
    if (x%i == 0) res+=i;
  return res;
}

vi primeFactors(ll  N) {
  vi factors;
  ll PF_idx = 0, PF = primes[PF_idx];
  while (PF*PF <= N) {
    while (N%PF == 0) { N/=PF; factors.push_back(PF);}
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (PF * PF <= N) {
    ll power = 0;
    while (N%PF == 0) { N/=PF; power++;}
    ans *= ((ll)pow((double)PF, power+1.0)-1) / (PF-1);
    PF = primes[++PF_idx];
  }
  if (N!=1) ans*=((ll)pow((double)N,2.0) - 1)/(N-1);
  return ans;
}

int main() {
  sieve(100000);

  for (ll i = 2; i < 5000000; i++)
    if (sumDiv(i) >= 34000000/10) { cout << i << endl; break;}
  vector<int> lol(50*1000000, 0);
  for (int i = 1; i < 1000000; i++) {
    for (int j = 1; j <= 50; j++) {
      lol[i*j] += i*11;
    }
    if (lol[i] >= 34000000) { cout << i << endl; break;}
  }
    

  return 0;
}
