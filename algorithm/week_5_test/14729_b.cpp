#include <bits/stdc++.h>
using namespace std;

int N;
double num;
priority_queue<double> pq;
vector<double> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;

    if (pq.size() == 7) {
      pq.push(num);
      pq.pop();
    } else {
      pq.push(num);
    }
  }

  while (pq.size()) {
    v.push_back(pq.top());
    pq.pop();
  }

  reverse(v.begin(), v.end());

  cout.precision(3);
  cout << fixed;

  for (double i : v) {
    cout << i << '\n';
  }

  return 0;
}