#include <bits/stdc++.h>
using namespace std;

int K, M, N, a[1004], b[1004], a_psum[2008], b_psum[2008], ret;
map<int, int> mpa, mpb;

void make(int n, int psum[], map<int, int> & mp){ 
  for(int interval = 1; interval <= n; interval++){
    for(int start = interval; start <= n + interval - 1; start++){
      int sum = psum[start] - psum[start - interval];
      mp[sum]++;   
      if(interval == n) break;
    } 
  }   
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K;
  cin >> M >> N;

  for (int i = 1 ; i <= M; i++) {
    cin >> a[i];
    a_psum[i] = a_psum[i - 1] + a[i];
  }
  for (int i = M + 1; i <= M * 2; i++) a_psum[i] = a_psum[i - 1] + a[i - M];

  for (int i = 1 ; i <= N; i++) {
    cin >> b[i];
    b_psum[i] = b_psum[i - 1] + b[i];
  }
  for (int i = N + 1; i <= N * 2; i++) b_psum[i] = b_psum[i - 1] + b[i - N];

  make(M, a_psum, mpa);
  make(N, b_psum, mpb);

  ret = mpa[K] + mpb[K];
  for (int i = 1; i < K; i++) {
    ret += mpa[i] * mpb[K - i];
  }

  cout << ret << '\n';

  return 0;
}