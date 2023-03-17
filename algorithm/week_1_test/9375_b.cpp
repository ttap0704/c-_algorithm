// 9375 복습
#include <bits/stdc++.h>
using namespace std;

int N, M;
string a, b;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> M;

    // ret를 케이스마다 넣어주어야함 :: 주의
    long long ret = 1;
    map<string, int> mp;
    for (int j = 0; j < M; j++) {
      cin >> a >> b;
      mp[b]++;
    }

    for (auto v : mp) {
      ret *= ((long long)v.second + 1);
    }

    cout << ret - 1 << "\n";
  }


  return 0;
}