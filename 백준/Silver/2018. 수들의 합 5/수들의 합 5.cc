#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int en = 1, sum = 1, cnt = 1;
    for(int st = 1; st <= n; st++) {
        while(sum < n && en != n) {
            en++;
            if(en != n) sum += en;
        }

        // 여기 왔다는 것은 sum == n 이거나 en == n
        if(en == n) break;
        if(sum == n) cnt++;
        sum -= st;
    }

    cout << cnt;

}