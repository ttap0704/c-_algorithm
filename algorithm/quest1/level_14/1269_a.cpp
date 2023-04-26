#include <bits/stdc++.h>
using namespace std;

int N, M, num, cnt;
map<int, int> a;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> num;
    a[num]++;
  }

  for (int i = 0; i < M; i++) {
    cin >> num;
    a[num]++;
  }

  for (auto i : a) {
    if (i.second == 1) cnt++;
  }

  cout << cnt << '\n';
  
  return 0;
}