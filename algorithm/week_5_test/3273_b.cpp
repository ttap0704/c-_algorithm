#include <bits/stdc++.h>
using namespace std;

int N, a[100004], answer, from, to, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cin >> answer;

  sort(a, a + N);
  from = 0;
  to  = N - 1;
  while (from != to) {
    int num = a[from] + a[to];
    if (num == answer) {
      from++;
      ret++;
    } else if (num > answer) to--;
    else if (num < answer) from++;
  }

  cout << ret << '\n';
  
  return 0;
}