#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    v.push_back(i);
  }

  for (int i = 0; i < M; i++) {
    cin >> a >> b;

    reverse(v.begin() + a - 1, v.begin() + b);
  }
  for (int i : v) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}