#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> a >> b;

    cout << (a + b) << '\n';
  }
  return 0;
}