#include <bits/stdc++.h>
using namespace std;

int N, num, cnt = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;

    if (num == 1) continue;


    int i2 = 1;
    int check = 0;
    while (i2 < num) {
      if (num % i2 == 0) check++;
      i2++;
    }

    if (check == 1) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}