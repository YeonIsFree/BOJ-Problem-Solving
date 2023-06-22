#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> arr;

    int cnt = n;
    while(cnt--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cout << arr[0] * arr[n-1];
}