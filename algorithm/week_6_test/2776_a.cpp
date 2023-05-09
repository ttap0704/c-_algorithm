#include <bits/stdc++.h>
using namespace std;

int T, N, M, n;

int check (int n, vector<int> &v) {
  int l = 0, r = v.size() - 1;
  bool flag=  0;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (v[mid] > n) r = mid -1 ;
    else if (v[mid] < n) l = mid + 1;
    else return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> n;
      v.push_back(n);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> n;
      cout << check(n, v) << '\n';
    }
  }

  return 0;
}