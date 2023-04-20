#include <bits/stdc++.h>
using namespace std;

int N, K, mx = 0, v[50];
string s;

bool checkDefault(int here) {
  if (here == 'a' - 'a' || here == 'n' - 'a' || here == 't' - 'a' || here == 'i' - 'a' || here == 'c' - 'a') return true;
  return false;
}

void go (int here, int cnt, int learn) {
  if (cnt == 0) {
    // cout << "learn : " << learn << '\n';
    // for (int i = 0; i < 26; i++) {
    //   if (learn & (1 << i)) cout << (char)(i + 'a') << ' ';
    // }
    // cout << '\n';
    int sum = 0;
    for (int word : v) {
      if (word && (word & learn) == word) sum++;
    }

    mx = max(sum, mx);
    return;
  }

  if (here == 26) return;

  go(here + 1, cnt, learn);
  if (!checkDefault(here)) {
    go(here + 1, cnt - 1, learn | (1 << here));
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> s;
    
    for (char c : s) {
      v[i] |= (1 << (c - 'a'));
    }
  }

  if (K < 5) {
    cout << 0 << '\n';
  } else {
    int a = 0;
    a |= (1 << ('a' - 'a'));
    a |= (1 << ('n' - 'a'));
    a |= (1 << ('t' - 'a'));
    a |= (1 << ('i' - 'a'));
    a |= (1 << ('c' - 'a'));

    go(0, K - 5, a);
    cout << mx << '\n';
  }

  return 0;
}