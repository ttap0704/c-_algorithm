#include <bits/stdc++.h>
using namespace std;

int N, x, y;
map<int, priority_queue<int, vector<int>, greater<int>>> mp_x, mp_y;
map<int, int> visited_x, visited_y;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    mp_x[y].push(x);
    mp_y[x].push(y);
  }

  return 0;
}