#include <bits/stdc++.h>
using namespace std;

int N, M, mx = 0, arr[104];

void combi (int start, vector<int> v) {
  if (v.size() == 3) {
    int sum = 0;
    for (int i : v) sum += i;

    if (sum <= M) {
      mx = max(mx, sum);
    }
    return;
  }

  for (int i = start; i < N; i++) {
    v.push_back(arr[i]);
    combi(i + 1, v);
    v.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  combi(0, {});

  cout << mx << '\n';
  return 0;
}