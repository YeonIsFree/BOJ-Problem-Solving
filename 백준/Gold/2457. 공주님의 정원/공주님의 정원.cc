#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> f[100003];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i = 0; i < n; i++) {
      int sm, sd, em, ed;
      cin >> sm >> sd >> em >> ed;
      f[i].first = (sm * 100) + sd;
      f[i].second = (em * 100) + ed;
  }

  // 꽃들의 수는 가능한 적게 만들어야 하므로,
  // 지금 피어있는 꽃들 중 가장 마지막에 지는 꽃을 선택해나간다. 
  int now = 301;
  int cnt = 0;
  while(now < 1201) {
    int nx = now;
    for(int i = 0; i < n; i++) {
      if(f[i].first <= now && f[i].second > nx)
        nx = f[i].second;
    }

    if(now == nx) {
      cout << 0;
      return 0;
    }

    cnt++;
    now = nx;
  }
  cout << cnt;
}