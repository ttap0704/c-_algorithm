#include <bits/stdc++.h>
using namespace std;

int N, num;
map<int, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    mp[num]++;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;

    cout << mp[num] << ' ';
  }

  return 0;
}