#include <bits/stdc++.h>
#define MAX 123456 * 2
using namespace std;

int N;
bool era[MAX + 4];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  era[0] = 1;
  era[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    if (era[i]) continue;
    for (int j = i * 2; j <= MAX; j += i) {
      era[j] = 1;
    }
  }

  while (true) {
    cin >> N;
    if (N == 0) break;

    int ret = 0;
    for (int i = N + 1; i <= N * 2; i++) {
      if (!era[i]) ret++;
    }

    cout << ret << '\n';
  }

  return 0;
}