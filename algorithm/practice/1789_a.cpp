#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll S, ret;
vector<ll> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  ll i = 1;
  while (S > 0) {
    S -= i;
    i++;
    ret++;
  }
  if (S < 0) ret--;

  cout << ret << '\n';

  return 0;
}