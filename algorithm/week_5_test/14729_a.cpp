#include <bits/stdc++.h>
using namespace std;

int N;
double num;
map<double, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int> pq;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    mp[num]++;
  }

  cout.precision(3);
  cout << fixed;
  int cnt = 0;
  for (auto i : mp) {
    for (int j = 0; j < i.second; j++) {
      cout << i.first << '\n';
      cnt++;
      if (cnt >= 7) break;
    }
    if (cnt >= 7) break;
  }
  return 0;
}