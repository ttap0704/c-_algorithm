#include <bits/stdc++.h>
using namespace std;

int A1, B1, C1, D1;
map<pair<int, int>, int> visited;

int check (int a, int b, int A, int B, int C, int D) {
  map<pair<int, int>, int> tmp;
  visited = tmp;
  int ret = 0;
  while (a != C || b != D) {
    if (visited[{a, b}]) {
      ret = 1e9;
      break;
    }
    visited[{a, b}] = 1;

    if (b == B) {
      b = 0;
    } else {
      if (a == 0) {
        a = A;
      } else {
        if (a + b <= B) {
          b += a;
          a = 0;
        } else {
          a = (a + b) - B;
          b = B;
        }
      }
    }

    ret++;
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A1 >> B1 >> C1 >> D1;

  if (A1 == C1 && B1 == D1) {
    cout << 2 << '\n';
  } else {
    int ret = min(check(0, 0, A1, B1, C1, D1), check(0, 0, B1, A1, D1, C1));
    if (ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';
  }

  return 0;
}