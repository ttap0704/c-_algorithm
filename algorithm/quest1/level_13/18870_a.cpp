#include <bits/stdc++.h>
using namespace std;

int N, x;
map<int, int> visited, mp;
vector<int> v, v2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x;
    v.push_back(x);
    v2.push_back(x);
  }

  sort(v.begin(), v.end());

  int num = 0;
  for (int i = 0; i < v.size(); i++) {
    if (visited[v[i]] != 1) {
      mp[v[i]] = num;
      num++;
    }
    visited[v[i]] = 1;
  }

  for (int i : v2) {
    cout << mp[i] << ' ';
  }
  cout << '\n';

  return 0;
}