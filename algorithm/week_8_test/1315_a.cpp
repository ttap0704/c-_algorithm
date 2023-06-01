#include <bits/stdc++.h>
using namespace std;

struct Quest {
  int stat, pn, idx;

  Quest(int stat, int pn, int idx) : stat(stat), pn(pn), idx(idx) {};

  bool operator < (const Quest & a) const {
    return stat > a.stat;
  };
};

int N, a, b, mxa, mxb, p, dp[1004][1004], mx_stat = 1, visited[1004];
priority_queue<Quest> pq1, pq2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> p;

    if (a < b) {
      for (int i = a; i <= 1000; i++){
        for (int j = 1; j <= 1000; j++) {
          dp[i][j]++;
        }
      }
    } else if (a > b) {
      for (int i = 1; i <= 1000; i++){
        for (int j = b; j <= 1000; j++) {
          dp[i][j]++;
        }
      } 
    } else {
      for (int i = a; i <= 1000; i++){
        for (int j = b; j <= 1000; j++) {
          dp[i][j]++;
        }
      } 
    }

    pq1.push({a, p, i});
    pq2.push({b, p, i});
  }

  while (true) {
    if (pq1.empty() && pq2.empty()) break;
    if (pq1.top().stat > mx_stat && pq2.top().stat > mx_stat) break;


    while (pq1.size() && pq1.top().stat <= mx_stat) {
      if (!visited[pq1.top().idx]) {
        mx_stat = min(1001, pq1.top().pn + mx_stat);
        visited[pq1.top().idx] = 1;
      }
      pq1.pop();
    }

    while (pq2.size() && pq2.top().stat <= mx_stat) {
      if (!visited[pq2.top().idx]) {
        mx_stat = min(1001, pq2.top().pn + mx_stat);
        visited[pq2.top().idx] = 1;
      }
      pq2.pop();
    }

  }

  int ret = 0;
  for (int i = 1; i <= mx_stat - 1; i++) {
    ret = max(ret, dp[i][mx_stat - i]);
  }

  cout << ret << '\n';

  return 0;
}