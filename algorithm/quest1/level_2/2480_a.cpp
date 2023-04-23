#include <bits/stdc++.h>
using namespace std;

int A, B, C, mx = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;

  mx = max(A, mx);
  mx = max(B, mx);
  mx = max(C, mx);

  if (A == B && B == C) {
    cout << (10000 + (mx * 1000)) << '\n';
  } else if (A != B && B != C && A != C) {
    cout << (mx * 100) << '\n';
  } else {
    if (A == B) {
      cout << (1000 + (B * 100)) << '\n';
    } else if (B == C) {
      cout << (1000 + (B * 100)) << '\n';
    } else if (A == C) {
      cout << (1000 + (A * 100)) << '\n';
    }
  }

  return 0;
}