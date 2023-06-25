#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, a[100004];
ll ret, psum[100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }

  for (int i = 1; i <= N; i++) {
    ret += a[i] * (psum[N] - psum[i]);
  }

  cout << ret << '\n';
  
  return 0;
}