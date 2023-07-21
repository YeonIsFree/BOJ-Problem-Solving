#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, b, c;
ll arr[1000002];
ll ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> b >> c;

    // ----
    ll sum = 0;    // 필요한 부감독관의 수
    for(int i = 0; i < n; i++) {
        ll students = arr[i] - b;       // 총감독관이 보는 애들을 제외한 나머지 학생들
        if(students <= 0) continue;     // 총감독관 혼자 다 커버 가능한 교실일 경우 패스
        if(students % c != 0) sum += (students / c + 1);
        else sum += students / c;
    }
    ans = n + sum;
    cout << ans;
}