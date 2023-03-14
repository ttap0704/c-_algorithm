#include <bits/stdc++.h>
using namespace std;

int N, M;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  int max = -10000004;
  vector<int> temp;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int cur_temp;
    cin >> cur_temp;

    temp.push_back(cur_temp);
    sum += cur_temp;

    if (temp.size() == M) {
      if (max < sum) {
        max = sum;
      }
      sum -= temp[0];
      temp.erase(temp.begin());
    }
  }

  cout << max << "\n";

  return 0;
}