#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll num, ret = 0;
int N;
deque<ll> dq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    if (dq.size() < 1) dq.push_back(num);
    else {
      if (dq.back() > num) {
        int dq_size = dq.size();
        for (int j = 0; j < dq_size - 1; j++) {
          dq.pop_front();
        }
        
        ret += 1;
      } else if (dq.back() < num) { 
        ret += dq.size();

        int dq_back = dq.back();
        dq.pop_back();
        int idx = 0;
        for (int j : dq) {
          if (j >= num) {
            dq.erase(dq.begin() + idx);
          }
          idx++;
        }

        dq.push_back(dq_back);
        // int dq_size = dq.size();
        // for (int j = 0; j < dq_size - 1; j++) {
        //   if (dq[i] < num) {
        //     dq.erase(dq.begin() + i);
        //   }
        // }
      } else {
        ret += dq.size();
      }
      dq.push_back(num);
    }
  }

  

  cout << ret << '\n';
  return 0;
}