// 1629 복습
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, C;
ll go (ll a, ll b) {
  if (b == 1) return a % C;

  // 처음 A^1 % C의 값이 나오고
  // ret = A^1 % C;
  // 1승값 증가하면서 토대로 모듈러 연산
  ll ret = go(a, b / 2);
  ret = (ret * ret) % C;
  if (b % 2 == 1) ret = (ret * a) % C;
  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  cout << go(A, B) << "\n";
  return 0;
}