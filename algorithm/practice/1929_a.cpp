#include <bits/stdc++.h>
using namespace std;

int M, N;
bool era[1000004];

void setEra (int end) {
  era[0] = 1; era[1] = 1;
  for (int i = 2; i <= end; i++) {
    if (era[i]) continue;
    for (int j = i * 2; j <= end; j += i) {
      era[j] = 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;
  setEra(N);
  for (int i = M; i <= N; i++) {
    if (!era[i]) cout << i << '\n';
  }

  return 0;
}