#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c >> d >> e >> f;

  for (int i = -999; i < 1000; i++) {
		for (int j = -999; j < 1000; j++) {
			if (a * i + b * j == c) {
				if (d * i + e * j == f) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}

  return 0;
}