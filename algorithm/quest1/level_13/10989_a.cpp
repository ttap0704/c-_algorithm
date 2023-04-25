#include <bits/stdc++.h>
using namespace std;

int a[10004], num, N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    a[num]++;
  }

  for (int i = 1; i < 10004; i++) {
    for (int j = 0; j < a[i]; j++) {
      cout << i << '\n';
    }
  }
  return 0;
}