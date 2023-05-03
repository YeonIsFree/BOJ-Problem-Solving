#include <bits/stdc++.h>
using namespace std;

long long s, sum, cnt;

// S가 크므로 long long 자료형을 사용해야한다.
// 더하는 수의 갯수가 최대한 많아야하므로 1, 2, 3 ... 처럼 가장 작은 수부터 차례로 더해나가는 것이 유리하다 -> 그리디
// S에 딱 맞게 떨어지지 않을 수 있다. 그냥 S에 가장 가까운 합을 찾으면 된다.

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;

    long long n = 1; // 더해나갈 숫자
    while(sum < s) {
        
        // // 확인
        // cout << "현재까지의 sum은 : " << sum << '\n';
        // cout << "현재까지의 cnt는 : " << cnt << '\n';
        // cout << "지금 더할 n은 : " << n << '\n';
        // cout << "==============" << '\n';
        // //

        sum += n++;
        cnt++;
        // if(sum > s) break;
        // else cnt++;
    }
    if(sum > s) cout << cnt - 1;
    else cout << cnt;
}