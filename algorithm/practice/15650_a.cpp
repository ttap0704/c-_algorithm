#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;

void combi (int start, vector<int> v) {
  if (v.size() == M) {
    for (int i : v) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int i = start + 1; i < nums.size(); i++) {
    v.push_back(nums[i]);
    combi(i, v);
    v.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) nums.push_back(i);

  combi(-1, {});

  return 0;
}