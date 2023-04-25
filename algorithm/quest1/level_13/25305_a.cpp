#include <bits/stdc++.h>
using namespace std;

int N, K, num;
vector<int> v;

bool customSort (int i, int j) {
  return i > j;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end(), customSort);

  cout << v[K - 1] << '\n';

  return 0;
}