#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> a[54];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second;
  }

  for (int i = 0; i < N; i++) {
    int r = 1;
    for (int j = 0; j < N; j++) {
      if (a[i].first < a[j].first && a[i].second < a[j].second) {
        r++;
      }
    }

    printf("%d ", r);
  }

  return 0;
}