#include <bits/stdc++.h>
using namespace std;

int n, m;
long long s[1000001];
long long c[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    // 입력 배열을 따로 두지 않고 바로 누적 합 배열로 저장
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        cin >> tmp;
        s[i] = s[i-1] + tmp;
    }

    // 부분 합 배열을 m으로 나눈 나머지로 갱신
    for(int i = 1; i <= n; i++) {
        int tmp = s[i] % m;
        s[i] = tmp;
    }

    // 나머지들의 등장 횟수를 세어주고 c에 저장한다.
    for(int i = 1; i <= n; i++) {
        int mod = s[i];
        c[mod]++;
    }

    long long cnt = c[0];
    for(int i = 0; i < m; i++) {
        if(c[i] <= 1) continue;
        cnt += (c[i] * (c[i] - 1) / 2);
    }

    cout << cnt << '\n';
}