#include <bits/stdc++.h>
using namespace std;

int n;
int t[1003];


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> t[i];
  sort(t, t+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (n - i) * t[i];
  }

  cout << ans;
  
}