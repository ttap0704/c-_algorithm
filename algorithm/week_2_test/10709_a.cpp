#include <bits/stdc++.h>
using namespace std;
int H, W, a[104][104], cloud = -1;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> s;
    for (int j = 0; j < W; j++) {
      a[i][j] = s[j] == '.' ? 0 : 1;
    }
  }

  for (int i = 0; i < H; i++) {
    cloud = -1;
    for (int j = 0; j < W; j++) {
      if (a[i][j] == 1) {
        cloud = 0;
      } else if (cloud != -1) {
        cloud++;
      }

      cout << cloud << " ";
    }
    cout << "\n";
  }

  return 0;
}