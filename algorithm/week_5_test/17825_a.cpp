#include <bits/stdc++.h>
using namespace std;

int visited[34], score[34], mal[4] = {0, 0, 0, 0}, moving[10], mx = 0;
vector<int> adj[34];

int move (int idx, int mal_idx) {
  int move_cnt = moving[idx];
  int cur_mal = mal[mal_idx];

  while (true) {
    if (!move_cnt || cur_mal == 32) break;

    if (move_cnt == moving[idx] && adj[cur_mal].size() == 2) {
      cur_mal = adj[cur_mal][1];
    } else {
      cur_mal = adj[cur_mal][0];
    }
    move_cnt--;
  }

  // cout << "idx : " << idx <<" // "<< cur_mal << " // " << mal[mal_idx] << "\n";

  return cur_mal;
}

void go (int cnt, int s) {
  if (cnt == 10) {
    mx = max(mx, s);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int tmp_mal = mal[i];
    if (tmp_mal == 32) continue;

    int cur_mal = move(cnt, i);
    if (visited[cur_mal]) continue;
    
    visited[mal[i]] = 0;
    if (cur_mal != 32) visited[cur_mal] = i + 1;
    mal[i] = cur_mal;
    // cout << "score : " << score[cur_mal] << '\n';
    go(cnt + 1, s + score[cur_mal]);
    mal[i] = tmp_mal;
    visited[mal[i]] = i + 1;
    visited[cur_mal] = 0;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 10; i++) {
    cin >> moving[i];
  }

  for (int i = 0; i <= 19; i++) {
    adj[i].push_back(i + 1);
    score[i] = i * 2;
  }

  adj[5].push_back(21); adj[21].push_back(22); adj[22].push_back(23); adj[23].push_back(24);
  adj[10].push_back(25); adj[25].push_back(26); adj[26].push_back(24);
  adj[15].push_back(27); adj[27].push_back(28); adj[28].push_back(29); adj[29].push_back(24);
  adj[24].push_back(30); adj[30].push_back(31); adj[31].push_back(20);
  adj[20].push_back(32);

  score[21] = 13; score[22] = 16; score[23] = 19; score[24] = 25;
  score[25] = 22; score[26] = 24;
  score[27] = 28; score[28] = 27; score[29] = 26;
  score[30] = 30; score[31] = 35;
  score[32] = 0; score[20] = 40;

  go(0, 0);
  
  cout << mx << '\n';

  return 0;
}