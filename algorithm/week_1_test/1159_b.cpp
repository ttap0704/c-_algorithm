// 1159 복습
#include <bits/stdc++.h>
using namespace std;

int N, alpha[26];
string final_player;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    string player;
    cin >> player;

    alpha[player[0] - 'a']++;
  }


  for (int i = 0; i < 26; i++) {
    if (alpha[i] >= 5) {
      final_player += char(i + 'a');
    }
  }

  if (final_player.size() == 0) cout << "PREDAJA\n";
  else cout << final_player << "\n";

  return 0;
}