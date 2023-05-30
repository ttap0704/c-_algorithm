#include <bits/stdc++.h>
using namespace std;

int T, N;
priority_queue<int, vector<int>, greater<int>> pq;
map<int, pair<int ,int>> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    if (N == 0) {
      if (pq.size()) {
        int i = pq.top();
        if (mp[i].first > 0) {
          mp[i].first--;
          i *= -1;
        } else {
          mp[i].second--;
        }
        cout << i << '\n';
        pq.pop();
      } else {
        cout << 0 << '\n';
      }
    } else {
      if (N < 0) N *= -1, mp[N].first++;
      else mp[N].second++;

      pq.push(N);
    }
  }
  
  return 0;
}