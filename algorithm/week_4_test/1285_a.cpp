#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, mn = INF, a[44];
string s;

void go (int here) {
  if (here == N) {
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < N; j++) {
        if (a[j] & (1 << i)) cnt++;
      }
      sum += min(cnt, N - cnt);
    }
    mn = min(mn, sum);
    return;
  }

  go(here + 1);
  a[here] = ~a[here];
  go(here + 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'T') a[i] |= (1 << j);
    }
  }

  go(0);
  cout << mn << '\n';

  // for (int i = 0; i < N; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << "\n";

  return 0;
}