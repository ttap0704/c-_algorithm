#include <bits/stdc++.h>
using namespace std;

int N, num;
string s;
vector<string> v[204];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num >> s;

    v[num].push_back(s);
  }

  for (int i = 1; i < 204; i++) {
    if (v[i].size()) {
      for (string tmp : v[i]) {
        cout << i << ' ' << tmp << '\n';
      }
    }
  }

  return 0;
}