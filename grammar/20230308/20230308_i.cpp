#include <bits/stdc++.h>
using namespace std;

// 기본적으로 map은 정렬이 됨

// 자동으로 정렬이 되지 않는 map
unordered_map<string, int> umap;

int main () {
  umap["a"] = 1;
  umap["c"] = 1;
  umap["b"] = 1;

  for(auto it : umap){
    cout << it.first << " : " << it.second << '\n';
  }

  return 0;
}