#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> S;

    cout << S[0] << S[S.size() - 1] << '\n';
  }

  return 0;
}