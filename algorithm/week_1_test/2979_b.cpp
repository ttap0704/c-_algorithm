// 2979 복습
#include <bits/stdc++.h>
using namespace std;

int A, B, C, t[101], sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;

    for (int i = a; i < b; i++) {
      t[i]++;
    }
  }

  for (int i = 0; i < 101; i++) {
    if (t[i] == 0) continue;

    if (t[i] == 1) sum += A * t[i];
    else if (t[i] == 2) sum += B * t[i];
    else if (t[i] == 3) sum += C * t[i];
  }

  cout << sum << "\n";

  return 0;
}