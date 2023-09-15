#include <bits/stdc++.h>
using namespace std;

int K, a[50];

void combi (int start, vector<int> &v) {
  if (v.size() == 6) {
    for (int i : v) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int i = start; i < K; i++) {
    v.push_back(a[i]);
    combi(i + 1, v);
    v.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> K;
    if (K == 0) break;

    memset(a, 0, sizeof(a));
    for (int i = 0; i < K; i++) {
      cin >> a[i];
    }

    vector<int> v;
    combi(0, v);
    cout << '\n';
  }

  return 0;
}