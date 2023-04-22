#include <bits/stdc++.h>
using namespace std;

int N, V, a[104], ret = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  cin >> V;

  for (int i = 0; i < N; i++) {
    if (a[i] == V) ret++;
  }

  cout << ret << '\n';

  return 0;
}