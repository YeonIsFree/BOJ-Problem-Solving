#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> isprime(1003, true);

void func(int n) {
    isprime[1] = false;
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(isprime[i] == false) continue; 
        for(int j = i; j <= n; j += i) {
            if(isprime[j] == false) continue;
            isprime[j] = false;
            cnt++;
            if(cnt == k) {
                cout << j;
                return;
            }
        }
    } // 모든 수에 대한 탐색 종료

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    func(n);
}