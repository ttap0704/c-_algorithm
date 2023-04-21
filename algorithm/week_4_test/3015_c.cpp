#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, num, ret;
stack<pair<ll, ll>> s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    
    int cnt = 1;

    while (s.size() && s.top().first <= num) {
      ret += s.top().second;

      if (s.top().first == num) {
        cnt = s.top().second + 1;
      } else {
        cnt = 1;
      }

      s.pop();
    }

    if (s.size()) ret++;
    s.push({num, cnt});
  }

  cout << ret <<'\n';

  return 0;
}