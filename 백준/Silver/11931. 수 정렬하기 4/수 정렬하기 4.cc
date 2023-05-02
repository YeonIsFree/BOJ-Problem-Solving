#include <bits/stdc++.h>
using namespace std;

int n;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin()+n, greater());
    for(int i : arr)
        cout << i << '\n';
}