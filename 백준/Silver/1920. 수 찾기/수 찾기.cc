#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr1[100001];
int arr2[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    sort(arr1, arr1+n);

    for(int i = 0; i < m; i++) {
        int target = arr2[i];
        if(binary_search(arr1, arr1+n, target)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}