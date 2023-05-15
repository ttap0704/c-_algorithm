#include <bits/stdc++.h>
using namespace std;

string N, K;
int ret = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> K;

  if (N == K) {
    cout << 0 << '\n';
    return 0;
  }

  while (true) {
    if (stoi(K) % 2 == 0) {
      K = to_string(stoi(K) / 2);
    } else {
      if (K.back() == '1') K.pop_back();
      else {
        ret = -1;
        break;
      }
    }

    // cout << "K : " << K <<'\n';
    ret++;
    if (K == N) break;
    if (K == "1") {
      ret = -1;
      break;
    } 
  }

  cout << ret << '\n';

  return 0;
}