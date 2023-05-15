#include <bits/stdc++.h>
using namespace std;

int N, a[54], b[54], ret;

bool customSort (int a, int b) {
  return a > b;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];

  sort(a, a + N);
  sort(b, b + N, customSort);

  for (int i = 0; i < N; i++) ret += (a[i] * b[i]);

  cout << ret << '\n';

  return 0;
}