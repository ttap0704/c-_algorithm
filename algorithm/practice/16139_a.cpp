#include <bits/stdc++.h>
using namespace std;

string s;
int N, start_idx, end_idx, p_sum[200004][26];
char alpha;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    int idx = (s[i - 1] - 'a');
    for (int j = 0; j < 26; j++) {
      if (idx == j) p_sum[i][j] = p_sum[i - 1][j] + 1;
      else p_sum[i][j] = p_sum[i - 1][j];
    }
  }

  cin >> N;
  while (N--) {
    cin >> alpha >> start_idx >> end_idx;
    cout << p_sum[end_idx + 1][alpha - 'a'] - p_sum[start_idx][alpha - 'a'] << '\n';
  }

  return 0;
}