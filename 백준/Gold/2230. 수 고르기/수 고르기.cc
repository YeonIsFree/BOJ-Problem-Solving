#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100003];
int ans = 0x7f7f7f7f;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    // { 2, 3, 9, 13, 22 }
    int st = 0, en = 0;
    while(en < n && st <= en) {
        if(arr[en] - arr[st] < m) {
            en++;
        } else { // arr[en] - arr[st] >= m
            ans = min(ans, arr[en] - arr[st]);
            st++;
        }
    }
    cout << ans;
}