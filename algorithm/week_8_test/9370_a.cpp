#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
typedef tuple<int, int, bool> TI;

const int INF = 1e9;
int T, n, m, t, s, g, h, a, b, d, x, dist[2002][2];
priority_queue<TI, vector<TI>, greater<TI>> pq;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    fill(&dist[0][0], &dist[0][0] + (2002 * 2), INF);
    vector<PI> adj[2002];
    v.clear();

    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> d;
      adj[a].push_back({d, b});
      adj[b].push_back({d, a});
    }

    for (int i = 0; i < t; i++) {
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());

    pq.push({0, s, 0});
    dist[s][0] = 0;

    while (pq.size()) {
      int here, here_dist;
      bool visited;

      tie(here_dist, here, visited) = pq.top();
      pq.pop();

      for (PI p : adj[here]) {
        int there = p.second;
        int there_dist = p.first;
        bool there_visited = visited;
        if (!visited) {
          if ((here == g && there == h) || (here == h && there == g)) there_visited = 1;
        }

        if (dist[there][there_visited] > dist[here][visited] + there_dist) {
          dist[there][there_visited] = dist[here][visited] + there_dist;
          pq.push({dist[there][there_visited], there, there_visited});
        }
      }
    }

    for (int i : v) {
      if (dist[i][1] == INF && dist[i][0] == INF) continue;
      
      if (dist[i][1] <= dist[i][0]) cout << i << ' ';
      // cout << dist[i][1] << " : " << dist[i][0] << '\n';
    }
    cout << '\n';
  }
  return 0;
}