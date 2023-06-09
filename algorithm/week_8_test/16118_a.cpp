#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
typedef tuple<int, int, bool> TI;

const int INF = 1e9;
int N, M, a, b, d, dist[4004], dist2[4004][2], ret;
vector<PI> adj[4004];

void moveFox () {
  fill(dist, dist + 4004, INF);
  priority_queue<PI, vector<PI>, greater<PI>> pq;
  pq.push({0, 1});
  dist[1] = 0;

  while (pq.size()) {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (dist[here] != here_dist) continue;
    for (PI p : adj[here]) {
      int there = p.second;
      int there_dist = p.first;
      if (dist[there] > dist[here] + there_dist) {
        dist[there] = dist[here] + there_dist;
        pq.push({dist[there], there});
      }
    }
  }
}

void moveWolf () {
  fill(&dist2[0][0], &dist2[0][0] + (4004 * 2), INF);
  priority_queue<TI, vector<TI>, greater<TI>> pq;
  pq.push({0, 1, 0});
  dist2[1][0] = 0;

  while (pq.size()) {
    int here_dist, here, cnt;
    tie(here_dist, here, cnt) = pq.top();
    pq.pop();

    if (dist2[here][cnt] != here_dist) continue;
    for (PI p : adj[here]) {
      int there = p.second;
      int there_dist = !cnt ? p.first / 2 : p.first * 2;
      if (dist2[there][!cnt] > dist2[here][cnt] + there_dist) {
        dist2[there][!cnt] = dist2[here][cnt] + there_dist;
        pq.push({dist2[there][!cnt], there, !cnt});
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> d;
    adj[a].push_back({d * 2, b});
    adj[b].push_back({d * 2, a});
  }
  

  moveFox();
  moveWolf();
  for (int i = 2; i <= N; i++) {
    int wolf_dist = min(dist2[i][0],  dist2[i][1]);
    if (wolf_dist > dist[i]) ret++;
  }

  cout << ret << '\n';

  return 0;
}