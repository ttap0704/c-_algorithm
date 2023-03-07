// memcpy(복사할 변수, 상대값, 크기)
// 특정 메모리값을 복사할 때 사용
// 주로 배열을 깊은 복사

#include <bits/stdc++.h>
using namespace std;

int a[5], temp[5];
int main () {
  for (int i = 0; i < 5; i++) a[i] = i;

  memcpy(temp, a, sizeof(a));

  for(int i : temp) cout << i << ' '; cout << '\n';

  a[4] = 1000;
  for(int i : a) cout << i << ' ';
  cout << '\n';

  for(int i : temp) cout << i << ' ';
  cout << '\n';

  memcpy(a, temp, sizeof(temp));
  for(int i : a) cout << i << ' ';
  cout << '\n';

  return 0;
}