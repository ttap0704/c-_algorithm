#include <bits/stdc++.h>
using namespace std;

int N, n, ret;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> n, v.push_back(n);

  sort(v.begin(), v.end());
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += v[i];
    ret += sum;
  }

  cout << ret << '\n';

  return 0;
}