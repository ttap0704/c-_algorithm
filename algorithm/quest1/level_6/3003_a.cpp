#include <bits/stdc++.h>
using namespace std;

int a[6] = {1, 1, 2, 2, 2, 8}, num;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 6; i++) {
    cin >> num;

    a[i] -= num;
  }

  for (int i = 0; i < 6; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}