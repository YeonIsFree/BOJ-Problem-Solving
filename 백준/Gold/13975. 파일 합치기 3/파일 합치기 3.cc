#include <bits/stdc++.h>
using namespace std;

int t, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        priority_queue<long long, vector<long long>, greater<>> Q;
        cin >> k;
        for(int i = 0 ; i < k; i++) {
            int tmp;
            cin >> tmp;
            Q.push(tmp);
        }

        long long sum = 0;
        while(Q.size() > 1) {
            long long a = Q.top();
            Q.pop();
            long long b = Q.top();
            Q.pop();
            sum += (a+b);
            Q.push(a+b);
        }        
        cout << sum << '\n';
    } // 모든 테스트 케이스 종료
}