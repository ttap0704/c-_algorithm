#include <bits/stdc++.h>
using namespace std;

bool che[4000001];
int N, ret, sum = 0, p, a[2000001], lo, hi;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 2; i <= N; i++) {
    if (che[i]) continue;
    for (int j = 2 * i; j <= N; j += i) {
      che[j] = 1;
    }
  }

  for (int i = 2; i <= N; i++) {
    if (!che[i]) a[p++] = i;
  }

  while (true) {
    if (sum >= N) sum -= a[lo++];
    else if (hi == p) break;
    else sum += a[hi++];
    if (sum == N) ret++;
  }

  cout << ret << '\n';

  return 0;
}