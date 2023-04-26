#include <bits/stdc++.h>
using namespace std;

int N, from, to, ret;
pair<int, int> L[1000004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L[i].first >> L[i].second;
  }

  sort(L, L + N);

  int from = L[0].first;
  int to = L[0].second;
  for (int i = 1; i < N; i++) {
    if (to < L[i].first) {
      ret += abs(to - from);

      from = L[i].first;
      to = L[i].second;
    } else {
      if (to < L[i].second) {
        to = L[i].second;
      }
    }
  }

  ret += abs(to - from);

  cout << ret << '\n';

  return 0;
}