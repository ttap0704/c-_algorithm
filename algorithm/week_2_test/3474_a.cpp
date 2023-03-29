// 팩토리얼의 0의 개수를 구하는 문제
// 10은 2 x 5이기 때문에
// 2의 제곱, 5의 제곱을 증가시키면서 각 값에 증가시킨 값을 나눔
// 2제곱과 5제곱으로 나눈 값의 갯수가 맞아 떨어져야 하기
// 2제곱 5제곱 둘 중 최소값을 구하면, 0의 개수를 알 수 있음

#include <bits/stdc++.h>
using namespace std;

int N, a;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    int ret2 = 0, ret5 = 0;
    for (int j = 2; j <= a; j *= 2) {
      ret2 += a / j;
    }

    for (int j = 5; j <= a; j *= 5) {
      ret5 += a / j;
    }

    cout << min(ret2, ret5) << "\n";
  }

  return 0;
}