#include <bits/stdc++.h>
using namespace std;

int N, H, M, num1, num2, a[7][34], b[7], res = -1;
vector<pair<int, int>> v;

bool check(int start, int level, vector<pair<int, int>> v2) {
  bool flag = 1;
  
  for (int i = 0; i < v2.size(); i++) {
    int _s = v2[i].first;
    int _l = v2[i].second;

    if ((start == _s || (start == _s + 1 || start == _s - 1)) && level == _l) {
      flag = 0;
      break;
    }
  }

  return flag;
}

void go (int start, int end, int level, vector<pair<int, int>> v2) {
  if (level == H + 1) {
    cout << start << " : " << end << "\n";
    b[start] = end;
    return;
  }

  cout << a[start][level] << "\n";
  if (a[start][level] == 0) {
    go(start, end, level + 1, v2);
  } else {
    if (check(start, level, v2)) {
      cout << "여기야?\n";
      go(start, a[start][level], level + 1, v2);
    } else {
      go(start, end, level + 1, v2);
    }
  }
}

bool checkSada (vector<pair<int, int>> v2) {
  bool check_sada = true;
  for (int i = 1; i <= N; i++) {
    cout << i << " :::: " << b[i] << "\n";
    if (i != b[i]) {
      check_sada = false;
      break;
    }
  }

  cout << "check : " << check_sada << "\n";

  return check_sada;
}

void combi (int start, vector<pair<int, int>> v2, int mx) {
  if (v2.size() == mx) {
    for (int i = 1; i <= N; i++) {
      memset(b, 0, sizeof(b));
      go(i, i, 0, v2);
      if (checkSada(v2)) {
        res = i;
      }
      return;
    }
  }

  for (int i = start; i < v.size(); i++) {
    v2.push_back({v[i].first, v[i].second});
    combi(i, v2, mx);
    v2.pop_back();
  }
} 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> H;
  if (M == 0) {
    cout << 0 << "\n";
    return 0;
  }

  for (int i = 0; i < M; i++) {
    cin >> num1 >> num2;

    a[num2][num1] = num2 + 1;
    a[num2 + 1][num1] = num2;

    v.push_back({num2, num2 + 1});
  }

  combi(0, {}, 1);
  // for (int i = 1 ; i <= 3; i++) {
  //   vector<pair<int, int>> tmp;
  //   combi(0, tmp, i);
  //   if (res != -1) break;
  // }

  cout << "res : " << res << "\n";
  
  return 0;
}