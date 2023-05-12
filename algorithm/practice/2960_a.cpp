#include <bits/stdc++.h>
using namespace std;

int N, K, che[1004], cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for (int i = 2; i <= N; i++){
    if (che[i]) continue;
    for (int j = i; j <= N; j += i) {
      if (che[j]) continue;
      che[j] = 1;
      cnt++;

      if (cnt == K) {
        cout << j << '\n';
        break;
      }
    }
    if (cnt >= K) {
      break;
    }
  }

  return 0;
}