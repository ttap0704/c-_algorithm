#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
vector<ll> v = {0, 1, 2};
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 3; i <= N; i++) {
    ll tmp = v[i - 1] + v[i - 2];
    v.push_back(tmp % 15746);
  }

  cout << v[N] << '\n';

  return 0;
}