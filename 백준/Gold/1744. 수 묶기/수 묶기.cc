#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> P, N;
long long ans;

void seq_sum(vector<int> v) {
  while(v.size() > 1) {
    ans += *(v.end() - 1) * *(v.end() - 2);
    v.pop_back();
    v.pop_back();
  }
  // 벡터의 길이가 음수일 경우 하나가 남으니까,
  if(v.size())
    ans += v[0];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> num;
    // 입력받은 수가 1이면 그냥 더해준다.
    if(num == 1) 
      ans++;
    // 입력받은 수가 양수일 경우
    else if(num > 0) 
      P.push_back(num);
    else // 입력받은 수가 음수일 경우 
      N.push_back(num);
  }

    sort(P.begin(), P.end());
    sort(N.begin(), N.end(), greater<>());

    seq_sum(P);
    seq_sum(N);

    cout << ans;
}