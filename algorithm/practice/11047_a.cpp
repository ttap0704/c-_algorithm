#include <bits/stdc++.h>
using namespace std;

int N, K, n, ret = 0;
vector<int> v;


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> n, v.push_back(n);

  for (int i = N - 1; i >= 0; i--) {
    if (v[i] > K) continue;

    ret += K / v[i];
    K %= v[i];
  }

  cout << ret << '\n';

  return 0;
}