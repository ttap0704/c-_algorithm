#include <bits/stdc++.h>
using namespace std;

struct Cmp {
  bool operator () (int &a, int &b) const {
    if (abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
  };
};

int N, n;
priority_queue<int, vector<int>, Cmp> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while (N--) {
    cin >> n;
    if (n == 0) {
      if (pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << 0 << '\n';
      }
    } else {
      pq.push(n);
    }
  }
  
  return 0;
}