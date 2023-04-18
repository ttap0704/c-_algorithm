#include <bits/stdc++.h>
using namespace std;

int N, a[1100], _end;
vector<int> ret[14];

void go (int _s, int _e, int level) {
  if (_s > _e) return;
  if (_s == _e) {
    ret[level].push_back(a[_s]);
    return;
  }
  
  int mid = (_s + _e) / 2;
  ret[level].push_back(a[mid]);
  go(_s, mid - 1, level + 1);
  go(mid + 1, _e, level + 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  _end = pow(2, N) - 1;

  for (int i = 0; i < _end; i++) {
    cin >> a[i];
  }

  go(0, _end, 1);
  for (int i = 1; i <= N; i++) {
    for (int j : ret[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}