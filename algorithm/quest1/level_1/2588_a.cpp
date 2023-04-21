#include <bits/stdc++.h>
using namespace std;

string A, B;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  int sum2 = 0;
  for (int i = 0; i < B.size(); i++) {
    int sum = 0;
    for (int j = 0; j < A.size(); j++) {
      int tmp = (B[i] - '0') * (A[j] - '0') * (int)pow(10, j);
      sum += tmp;
    }
    sum2 += sum * (int)pow(10, i);
    cout << sum << '\n';
  }

  cout << sum2 << '\n';

  return 0;
}