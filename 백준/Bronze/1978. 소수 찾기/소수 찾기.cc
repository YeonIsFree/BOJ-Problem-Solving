#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[103];

bool isprime(int n) {
    if(n == 1) return 0;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++)
        if(isprime(arr[i])) ans++;
    
    cout << ans;
}