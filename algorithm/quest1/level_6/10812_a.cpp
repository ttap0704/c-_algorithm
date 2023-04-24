#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, arr[104];
queue<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) arr[i] = i;

  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;

    for (int j = a; j < c; j++) {
      v.push(arr[j]);
    }

    for (int j = c; j <= b; j++) {
      arr[a] = arr[j];
      a++;
    }
    // cout << "a : " << a << '\n';
    // cout << "v.size() : " << v.size() << '\n';
    for (int j = a; j <= b; j++) {
      arr[j] = v.front();
      v.pop();
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}