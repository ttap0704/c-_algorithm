#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dq[18][18][18], N, a[18][18], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }

  return 0;
}