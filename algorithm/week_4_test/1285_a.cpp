#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, mn = INF, a[44];
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'T') a[i] |= (1 << j);
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";

  return 0;
}