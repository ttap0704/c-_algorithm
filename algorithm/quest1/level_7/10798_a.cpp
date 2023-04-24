#include <bits/stdc++.h>
using namespace std;

string s;
char a[5][15];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(a, 0, sizeof(a));

  for (int i = 0; i < 5; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      a[i][j] = s[j];
    }
  }

  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 5; i++) {
      if(a[i][j]) cout << a[i][j];
    }
  }
  cout << '\n';

  return 0;
}