#include <bits/stdc++.h>
using namespace std;

int N, T, a[104], m, s;

void goMan (int s) {
  for (int i = 1; i <= N; i++) {
    if (i % s == 0) a[i] = !a[i];
  }
}

void goWoman(int s) {
  a[s] = !a[s];

  for (int i = 1; a[s - i] == a[s + i]; i++) {
    if (s - i < 1 || s + i > N) break;
    
    a[s + i] = !a[s + i];
    a[s - i] = !a[s - i];
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];

  cin >> T;
  while (T--) {
    cin >> m >> s;

    if (m == 1) {
      goMan(s);
    } else {
      goWoman(s);
    }
  }
  
  for (int i = 1; i <= N; i++) {
    cout << a[i] << ' ';
    if (i % 20 == 0) cout << '\n';
  }

  return 0;
}