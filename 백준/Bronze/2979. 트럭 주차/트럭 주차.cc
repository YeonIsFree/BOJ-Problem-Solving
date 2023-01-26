#include <bits/stdc++.h>
using namespace std;

int a, b, c; // 한대, 두대, 세대 댔을 때 주차 요금
int n, m; // 주차 시작 시간, 주차 종료 시간 
int cnt[100]; // 시간당 주차된 차 수를 기록하는 배열
int total; // 주차 비용 총 합계

int main(void) {
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        cin >> n >> m;
        for(int t = n; t < m; t++) cnt[t]++;
    }
    // 시간은 시작 - 끝 => 이상 - 미만이다.
    for(auto i : cnt) {
        if(i == 1) total += 1 * a ;
        else if(i == 2) total += 2 * b ;
        else if(i == 3) total += 3 * c ;
    }

    cout << total;

    return 0;
}