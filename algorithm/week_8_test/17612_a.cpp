#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Shopping {
  ll ti, calc_id, id;
};

struct Cmp {
  bool operator() (Shopping &a, Shopping &b) const {
    if (a.ti == b.ti) return a.calc_id > b.calc_id;
    else return a.ti > b.ti;
  }
};

int N, K, id, ti;
ll ret;
priority_queue<Shopping, vector<Shopping>, Cmp> pq;
vector<Shopping> v;

bool cmp (Shopping &a, Shopping &b) {
  if (a.ti == b.ti) return a.calc_id > b.calc_id;
  else return a.ti < b.ti;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> id >> ti;

    if (i < K) {
      pq.push({ti, i + 1, id});
      continue;
    }

    v.push_back(pq.top());
    Shopping s = pq.top();
    pq.pop();
    pq.push({s.ti + ti, s.calc_id, id});
  }

  while (pq.size()) {
    v.push_back(pq.top());
    pq.pop();
  }
  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < N; i++) {
    ret += 1LL * v[i].id * (i + 1);
  }

  cout << ret << '\n';

  return 0;
}