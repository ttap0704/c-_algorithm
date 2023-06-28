#include <bits/stdc++.h>
using namespace std;

int T, n;
bool era[10004];

void setEra () {
  era[0] = 1; era[1] = 1;
  for (int i = 2; i <= 10000; i++) {
    if (era[i]) continue;
    for (int j = i * 2; j <= 10000; j += i) {
      era[j] = 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  setEra();
  cin >> T;
  while (T--) {
    cin >> n;

    pair<int, int> p;
    for (int i = n / 2; i >= 2; i--) {
      if (!era[i] && n - i >= 2 && !era[n - i]) {
        p = {i, n - i};
        break;
      }
    }

    cout << p.first << ' ' << p.second << '\n';
  }  

  return 0;
}