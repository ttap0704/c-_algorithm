#include <bits/stdc++.h>
using namespace std;

int T, K, num, di, mid1 = 2, mid2 = 6, ret, visited[1004];
deque<int> dq[1004];
queue<pair<int, int>> rotate_q;
char c;

void rotateArray (int idx, int di) {
  if (di == -1) {
    dq[idx].push_back(dq[idx].front());
    dq[idx].pop_front();
  } else {
    dq[idx].push_front(dq[idx].back());
    dq[idx].pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c;
      dq[i].push_back(c - '0');
    }
  }

  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> num >> di;
    rotate_q.push({--num, di});
  }


  while (rotate_q.size()) {
    int cnt = 1;
    int idx = rotate_q.front().first;
    int di = rotate_q.front().second;

    queue<pair<int, int>> next_q;
    next_q.push({idx, di});
    bool l_check = 1, r_check = 1;
    while (l_check || r_check) {
      di *= -1;
      if (idx - cnt >= 0 && l_check && dq[idx - cnt + 1][mid2] - dq[idx - cnt][mid1] != 0) next_q.push({idx - cnt, di});
      else l_check = 0;

      if (idx + cnt < T && r_check && dq[idx + cnt - 1][mid1] - dq[idx + cnt][mid2] != 0) next_q.push({idx + cnt, di});        
      else r_check = 0;

      cnt++;
    }

    while (next_q.size()) {
      int idx2 = next_q.front().first;
      int di2 = next_q.front().second;

      rotateArray(idx2, di2);
      next_q.pop();
    }
    
    rotate_q.pop();
  }

  for (int i = 0; i < T; i++) {
    if (dq[i][0] == 1) ret++;
  }
  cout << ret << '\n';

  return 0;
}