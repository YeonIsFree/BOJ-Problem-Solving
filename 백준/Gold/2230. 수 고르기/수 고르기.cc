#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0x7f7f7f7f;
vector<int> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int input = 0;
        cin >> input;
        s.push_back(input);
    }
    // { 1, 3, 5 }   m = 3
    sort(s.begin(), s.end());
    // 해당 수열을 정렬 후 처음 인덱스부터 끝까지 탐색을 하되 
    // 해당 인덱스의 값보다 M이 큰 값을 이분탐색을 하여 삽입할 인덱스를 찾을 수 있습니다. 
    // 즉, 정렬을 무너뜨리지 않고 해당 값을 추가할 인덱스(lower_bound)를 반환합니다.
    for(int i = 0; i < s.size(); i++) {
        auto idx = lower_bound(s.begin(), s.end(), s[i] + m);
        if(idx < s.end()) 
            ans = min(ans, abs(*idx - s[i]));
    }
    cout << ans;
}