#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, arr[104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> a >> b >> c;

    for (int j = a; j <= b; j++) {
      arr[j] = c;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';


  return 0;
}