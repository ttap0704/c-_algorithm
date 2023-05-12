#include <bits/stdc++.h>
using namespace std;

int N, mx = 0;
char a[54][54];

void rotate90 () {
  char tmp[54][54];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      tmp[i][j] = a[N - j - 1][i];
    }
  }

  memcpy(a, tmp, sizeof(a));
}

void check () {

  for (int i = 0; i < N; i++) {
    string s = "";
    for (int j = 0; j < N; j++) {
      if (s.size()) {
        if (s.back() == a[i][j]) {
          s += a[i][j];
        } else {
          s = a[i][j];
        }
      } else {
        s += a[i][j];
      }
      if (mx < s.size()) {
        mx = s.size();
      }
    }
  }

  for (int i = 0; i < N; i++) {
    string s = "";
    for (int j = 0; j < N; j++) {
      if (s.size()) {
        if (s.back() == a[j][i]) {
          s += a[j][i];
        } else {
          s = a[j][i];
        }
      } else {
        s += a[j][i];
      }
      if (mx < s.size()) {
        mx = s.size();
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N - 1; j++) {
        if (a[i][j] == a[i][j + 1]) continue;
        char tmp = a[i][j];
        a[i][j] = a[i][j + 1];
        a[i][j + 1] = tmp;

        check();

        tmp = a[i][j];
        a[i][j] = a[i][j + 1];
        a[i][j + 1] = tmp;
      }
    }

    if (k == 0) {
      rotate90();
    }
  }

  cout << mx << '\n';

  return 0;
}