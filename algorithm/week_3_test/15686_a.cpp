#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, a[54][54], score[54][54], ret = INF;
vector<pair<int, int>> v, cv;

int checkSize(vector<pair<int, int>> b) {
  int sum_val = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      // cout << a[i][j] << " ";
      if (a[i][j] != 1) continue;
      int min_val = INF;
      for (pair<int, int> pos : b) {
        int first_value = 0;
        int second_value = 0;
        if (i > pos.first) {
          first_value = i - pos.first;
        } else {
          first_value = pos.first - i;
        }

        if (j > pos.second) {
          second_value = j - pos.second;
        } else {
          second_value = pos.second - j;
        }

        min_val = min(first_value + second_value, min_val);
      }
      // cout << "min_val : " << min_val << "\n";
      sum_val += min_val;
    }
  }

  return sum_val;
}

void combi(int start, vector<pair<int, int>> b) {
  if (b.size() == M) {
    ret = min(checkSize(b), ret);
  }

  for (int i = start + 1; i < v.size(); i++) {
    b.push_back(v[i]);
    combi(i, b);
    b.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];

      if (a[i][j] == 2) {
        v.push_back({i, j});
      }
    }
  }

  combi(-1, cv);

  cout << ret << "\n";
  return 0;
}