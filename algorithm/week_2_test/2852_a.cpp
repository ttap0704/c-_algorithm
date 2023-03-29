#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, full_time = 48 * 60, a[3], te2, score[3];
ll te, ti, prev_te;
string team, cur_time;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> team >> cur_time;
    te = stoi(team);
    te2 = te == 1 ? 2 : 1;
    ti = (stoi(cur_time.substr(0, 2)) * 60) + stoi(cur_time.substr(3));
    score[te]++;
    if (score[te] > score[te2]) {
      a[te] = full_time - ti;
      if (i != 0) {
        a[te2] -= a[te];
      }
    }

    prev_te = te;
  }

  cout << "a[1] :: "<< a[1] / 60 << ":" << a[1] % 60 << "\n";
  cout << "a[2] :: "<< a[2] / 60 << ":" << a[2] % 60 << "\n";

  return 0;
}