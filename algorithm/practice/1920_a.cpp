#include <bits/stdc++.h>
using namespace std;

int N, M, n;
map<int, bool> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> n, mp[n] = 1;

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> n;
    cout << mp[n] << '\n';
  }

  return 0;
}