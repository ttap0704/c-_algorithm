#include <bits/stdc++.h>
using namespace std;

int N, K, d[5004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  vector<int> v;
  int cnt = 0, num = 0;
  while (v.size() != N) {
    if (d[num % N] == 0 && cnt == K) {
      v.push_back(num % N);
      d[num % N] = 1;
      cnt = 1;
      continue;
    }

    if (d[num % N] == 0) {
      cnt++;
    }
    num++;
  }

  cout << "<";
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) cout << N;
    else cout << v[i];
    if (i != v.size() - 1) cout << ", ";
  }
  cout << ">";


  return 0;
}