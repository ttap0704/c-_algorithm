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

  sort(arr, arr + N, less<int>());

  for (int i = 0; i < N; i++) {
    cout << "num : " << int(arr[i]) << "\n";
  }

  return 0;
}