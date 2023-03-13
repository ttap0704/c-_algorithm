#include <bits/stdc++.h>
using namespace std;

int N;
int alpha[26];
vector<string> strings;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    strings.push_back(s);
  }

  for (string i : strings) {
    alpha[i[0] - 'a']++;
  }

  string result;
  for (int i = 0; i < 26; i++) {
    
    if (alpha[i] >= 5) {
      char current_alpha = char(i + 'a');
      result += current_alpha;
    }
  }

  if (result.length() == 0) {
    result = "PREDAJA";
  }

  cout << result << "\n";

  return 0;
}