// 1940 복습
#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> M;

  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] + arr[j] == M) cnt++;
    }
  }

  cout << cnt << "\n";
  
  return 0;
}