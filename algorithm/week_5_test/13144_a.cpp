#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, num, visited[100004], _size, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> num;
    if (!visited[num]) {
      _size++;
    } else {
      if (_size < i - visited[num]) {
        _size++;
      } else {
        _size = i - visited[num];
      }
    }

    visited[num] = i;
    ret += _size;
  }

  cout << ret << '\n';

  return 0;
}