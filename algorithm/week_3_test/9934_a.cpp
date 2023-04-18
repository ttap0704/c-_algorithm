#include <bits/stdc++.h>
using namespace std;

int N, num = 1, num2;
vector<int> v;
vector<int> ret[2000];
vector<vector<int>> v2;
bool plus_val = 0;

void calc () {
  for (int i = 1; i <= N; i++) {
    num *= 2;
  }

  num -= 1;
}

void go (int cnt) {
  // cout << "size :  " << v2.size() << "\n";
  if (v2.size() == 0) return;

  vector<vector<int>> tmp_v;

  for (vector<int> i : v2) {
    int idx = i.size() / 2;
    ret[cnt].push_back(i[idx]);

    // for (int j : i) {
    //   cout << j << " ";
    // }
    // cout << "\n";

    if (i.size() != 1) {
      vector<int> start_v = vector<int>(i.begin(), i.begin() + idx);
      vector<int> end_v = vector<int>(i.begin() + idx + 1, i.end());

      // cout << "\n";
      // for (int j : start_v) {
      //   cout << j << " ";
      // }
      // cout << "\n";

      // for (int j : end_v) {
      //   cout << j << " ";
      // }
      // cout << "\n";

      tmp_v.push_back(start_v);
      tmp_v.push_back(end_v);
    }
    
  }

  v2 = tmp_v;
  go(cnt + 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  calc();

  for (int i = 0; i < num; i++) {
    cin >> num2;
    v.push_back(num2);
  }

  v2.push_back(v);
  go(0);

  for (int i = 0; i < num / 2 + 1; i++) {
    if (ret[i].size() == 0) continue; 
    for (int j : ret[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}