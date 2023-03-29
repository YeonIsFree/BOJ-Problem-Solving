#include <bits/stdc++.h>
using namespace std;

int x, y, z;
int arr[10];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> z;
  int res = x * y * z;
  while(res > 0) {
    arr[res % 10]++;
    res = res / 10;
  }
  for(int i = 0; i < 10; i++) {
    cout << arr[i] << '\n';
  }

}