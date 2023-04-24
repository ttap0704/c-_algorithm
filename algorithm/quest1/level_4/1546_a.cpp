#include <bits/stdc++.h>
using namespace std;

int N;
double num, a[1004], mx = 0, sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];

    mx = max(mx, a[i]);
  }

  for (int i = 0; i < N; i++) {
    sum += (a[i] / mx) * 100;
  }

  cout.precision(8);
  cout << sum / N << '\n';
  
  return 0;
}