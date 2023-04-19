#include <iostream>
#include <vector>
using namespace std;

int a[14], mal[4], n = 10;
int v[104];
vector<int> adj[54];

int move (int here, int cnt) {
  if (here == 100) return 100;

  if (adj[here].size() >= 2) {
    here = adj[here][1];
    cnt--;
  }


  while(cnt) {
    here = adj[here][0];
    cnt--;
    if (here == 100) break;
  }
  
  return here;
}

bool checkMal(int mal_idx, int next_idx) {
  if (next_idx == 100) return false;

  for (int i = 0; i < 4; i++) {
    if (i == mal_idx) continue;
    if (mal[i] == next_idx) return true;
  }

  return false;
}

void add (int here, int there) {
  adj[here].push_back(there);
}

void setMap() {
	for (int i = 0; i <= 19; i++) add(i, i + 1);
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);

	add(10, 27); add(27, 28); add(28, 24); add(24, 25);
	add(25, 26); add(26, 20); add(20, 100);

	v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10;
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
	v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
	v[29] = 28; v[30] = 27; v[31] = 26;
}

int go (int here) {
  if (here >= n) return 0;

  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int tmp_idx = mal[i];
    int next_mal_idx = move(tmp_idx, a[here]);
    // cout << "next_mal_idx : " << next_mal_idx << "\n";
    if (checkMal(i, next_mal_idx)) continue;
    mal[i] = next_mal_idx;
    ret = max(ret, go(here + 1) + v[next_mal_idx]);
    mal[i] = tmp_idx;
  }

  return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); setMap();
	for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << go(0) << "\n";
	return 0;
}