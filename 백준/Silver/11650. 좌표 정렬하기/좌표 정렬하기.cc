#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
pair<ll, ll> arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second;
        cout << '\n';
    }
}