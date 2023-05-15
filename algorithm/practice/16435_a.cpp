#include <bits/stdc++.h>
using namespace std;

int N, L, a[10004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);

  for (int i = 0; i < N; i++) {
    if (L >= a[i]) {
      L++;
    }
  }

  cout << L << '\n';

  return 0;
}