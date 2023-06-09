#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100002];
int sum[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + arr[i];
    
    while(m--) {
        int st, en;
        cin >> st >> en;
        cout << sum[en] - sum[st-1] << '\n';
    }
}