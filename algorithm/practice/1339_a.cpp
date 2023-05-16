#include <bits/stdc++.h>
using namespace std;

int N, score[26], ret;
string s;
vector<string> v;

bool customSort (int a, int b) {
  return score[a] > score[b];
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    v.push_back(s);

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
      int cur_num = s[i] - 'A';
      score[cur_num] += pow(10, i);
    }
  }

  sort(score, score + 26, greater<>());

  int num = 9;
  for (int i = 0; i < 26; i++) {
    if (score[i] == 0) break;

    ret += score[i] * num;
    num--;
  }

  cout << ret << '\n';

  return 0;
}