#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, t, p;
int mx;
vector<pair<int, int>> arr = { {-1, -1}, };

void func(int today, int sum) {
    mx = max(mx, sum);

    // Base condition
    if(today == n+1) return;

    // 1. 오늘의 상담을 할 경우 -- 퇴사 하기 전이어야 한다.
    if(today + arr[today].X - 1 <= n)
        func(today + arr[today].X, sum + arr[today].Y);

    // 2. 오늘의 상담을 안할 경우
    func(today + 1, sum);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
   
    for(int i = 0; i < n; i++) {
        cin >> t >> p;
        arr.push_back({t, p});
    }
    
    func(1, 0);

    cout << mx;

}