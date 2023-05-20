#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    long long cnt = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int target = -(arr[i] + arr[j]);
            cnt += upper_bound(arr+j+1, arr+n, target) - lower_bound(arr+j+1, arr+n, target);
        }
    }
    cout << cnt;
}