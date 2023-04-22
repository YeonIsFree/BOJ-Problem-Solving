#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[13];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;

  for(int i = n-1; i >= 0; i--) {
    ans += k / a[i];
    k = k % a[i];
  }
  cout << ans;
  
}