#include <bits/stdc++.h>
using namespace std;

int N;

void hanoi (int start, int mid, int end, int n) {
  if (n == 1) {
    cout << start << " " << end << '\n';
  } else {
    hanoi(start, end, mid, n - 1);
    cout << start << " " << end << '\n';
    hanoi(mid, start ,end, n - 1);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  cout << (int)pow(2, N) - 1 << '\n';
  hanoi(1, 2, 3, N);

  return 0;
}