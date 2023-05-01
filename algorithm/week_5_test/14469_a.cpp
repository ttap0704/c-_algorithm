#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
vector<pair<int, int>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;

    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  a = v[0].first;
  b = v[0].first + v[0].second;

  for (int i = 1; i < v.size(); i++) {
    a = v[i].first;
    if (b <= v[i].first) {
      b = v[i].first + v[i].second;
    } else if (b > v[i].first) {
      b += v[i].second;
    }
  }

  cout << b << '\n';
  
  return 0;
}