#include <bits/stdc++.h>
using namespace std;

int N, num;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for (int i : v) {
    cout << i << '\n';
  }

  return 0;
}