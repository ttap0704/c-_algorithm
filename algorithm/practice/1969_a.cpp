#include <bits/stdc++.h>
using namespace std;

int N, M, cnt[54][26], mx[54], ret2;
string s, ret1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      char c = s[j];

      cnt[j][c - 'A']++;
      mx[j] = max(cnt[j][c - 'A'], mx[j]);
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 26; j++) {
      if (cnt[i][j] == mx[i]) {
        ret1 += (j + 'A');
        break;
      }
    }
    ret2 += (N - mx[i]);
  }

  cout << ret1 << '\n';
  cout << ret2 << '\n';

  return 0;
}