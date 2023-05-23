#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, N;
vector<ll> v = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 11; i <= 100; i++) {
    v.push_back(v[i - 2] + v[i - 3]);
  }

  cin >> T;
  while (T--) {
    cin >> N;
    cout << v[N] << '\n';
  }

  return 0;
}