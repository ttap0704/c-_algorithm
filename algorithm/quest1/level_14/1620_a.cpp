#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<string, int> mp1;
map<int, string> mp2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> s;
    mp1[s] = i;
    mp2[i] = s;
  }

  for (int i = 0; i < M; i++) {
    cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      cout << mp2[stoi(s)] << '\n';
    } else {
      cout << mp1[s] << '\n';
    }
  }

  return 0;
}