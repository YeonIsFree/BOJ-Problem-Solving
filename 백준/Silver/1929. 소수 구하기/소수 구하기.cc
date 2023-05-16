#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<bool> isprime(1000002, true);

void func(int n) {
   isprime[1] = false;
   for(int i = 2; i*i <= n; i++) {
    if(isprime[i] == false) continue;
    for(int j = i*i; j <= n; j += i) {
        isprime[j] = false;
    } 
   }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    func(n);
    for(int i = m; i <= n; i++) {
        if(isprime[i]) cout << i << '\n';
    }

}