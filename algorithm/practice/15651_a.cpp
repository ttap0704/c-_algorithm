#include <bits/stdc++.h>
using namespace std;

int N, M;

void combi (vector<int> v) {
  if (v.size() == M) {
    for (int i : v) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    v.push_back(i);
    combi(v);
    v.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  combi({});

  return 0;
}