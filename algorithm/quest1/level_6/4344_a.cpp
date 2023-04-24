#include <bits/stdc++.h>
using namespace std;

double C, N, sum = 0, a[1004], cnt;
double avg, percent;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> C;
  for (int i = 0; i < C; i++) {
    sum = 0;
    cnt = 0;
    avg = 0;
    percent = 0;

    cin >> N;

    for (int j = 0; j < N; j++) {
      cin >> a[j];
      sum += a[j];
    }

    avg = (sum / N);

    for (int j = 0; j < N; j++) {
      if (a[j] > avg) cnt++;
    }

    percent = (cnt * 100) / N;

    cout.precision(3);
    cout << fixed;
    cout << percent << '%' << '\n';
  }

  return 0;
}