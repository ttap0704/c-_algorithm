#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, a[100004], b[100004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N - 1; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  b[N - 1] = 0;

  ll idx = 0;
  ret += (a[0] * b[0]);
  for (int i = 1; i < N; i++) {
    if (b[i] < b[idx]) {
      idx = i;
    }
    ret += (a[i] * b[idx]);
  }

  cout << ret << '\n';
  
  return 0;
}