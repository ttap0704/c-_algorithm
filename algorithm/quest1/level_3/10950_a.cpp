#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> A >> B;

    cout << (A + B) << '\n';
  }

  return 0;
}