#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Room {
  ll t, a, h;
} room[123500];
ll N, H, t, a, h, ret;

bool check (ll mid) {
  ll cur_hp = mid, cur_at = H;
  
  for (int i = 0; i < N; i++) {
    Room cur_room = room[i];
    if (cur_room.t == 1) {
      ll cnt = (cur_room.h / cur_at) + (cur_room.h % cur_at ? 1 : 0);
      cur_hp -= (cnt - 1) * cur_at;
    } else {
      cur_at += cur_room.a;
      cur_hp = min(mid, cur_hp + cur_room.h);
    }

    if (cur_hp <= 0) return false;
  }

  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> t >> a >> h;
    room[i] = {t, a, h};
  }

  ll lo = 1, hi = 1e18 + 4, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
     if (check(mid)) {
      ret = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ret << '\n';

  return 0;
}