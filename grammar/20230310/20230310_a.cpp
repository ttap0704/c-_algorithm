// 순열 : 1,2,3이 있을 때 -> 1,3,2 등으로 다른 순서로 섞는 연산
// n개의 집합 중 n개를 고르시오 = n!

// 1,2,3으로 만들 수 있는 3자리 자연수 = 3! / (3 - 3)!
// 1,2,3으로 만들 수 있는 1자리 자연수 = 3! / (3 - 1)!

// 두 번째 : 재귀함수를 사용한 방법
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}

void makePermutation(int n, int r, int depth) {
  if (r == depth) {
    // printV(v);
    return;
  } else {
    // cout<<n<<":"<<r<<":"<< depth << '\n';
  }

  for (int i = depth; i < n; i++) {
    swap(v[i], v[depth]);
    makePermutation(n, r, depth + 1);
    swap(v[i], v[depth]);
  }

  return;
}

int main () {
  for(int i = 0; i < 3; i++) v.push_back(a[i]); 
  makePermutation(3, 3, 0);
  return 0;
}