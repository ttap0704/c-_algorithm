#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    string s;

    for (int j = N; j >= 1; j--) {
      if (j > i) s += ' ';
      else s += '*';
    }

    cout << s << '\n';
  }

  return 0;
}