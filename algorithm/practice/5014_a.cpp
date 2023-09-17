#include <bits/stdc++.h>
#define MAX_N 1000004
using namespace std;

const int INF = 1e9;
int F, S, G, U, D, visited[MAX_N], ret = INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> F >> S >> G >> U >> D;

  queue<int> q;
  q.push(S);
  visited[S] = 1;

  while (q.size()) {
    int here = q.front();
    q.pop();

    if (here - D > 0 && !visited[here - D]) {
      q.push(here - D);
      visited[here - D] = visited[here] + 1;
    }

    if (here + U <= F && !visited[here + U]) {
      q.push(here + U);
      visited[here + U] = visited[here] + 1;
    }
  }

  if (visited[G]) cout << visited[G] - 1 << '\n';
  else cout << "use the stairs\n";
  

  return 0;
}