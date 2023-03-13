#include <bits/stdc++.h>
using namespace std;
int a[9];
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    cin >> a[i];
  }
  sort(a, a + 9);
  // 순열을 통해 구하는 방법
  // 9개 순열을 돌려 앞의 7개만 sum
  // 100나오면 return
  // 앞의 7개만 출력
  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) sum += a[i];
    if (sum == 100) break;
  } while (next_permutation(a, a + 9));

  for (int i = 0; i < 7; i++) cout << a[i] << "\n";

  return 0;
}