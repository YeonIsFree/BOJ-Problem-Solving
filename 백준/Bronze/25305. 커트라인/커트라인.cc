#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n, greater());
    cout << arr[k-1];
}