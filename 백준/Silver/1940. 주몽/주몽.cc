#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<int> sub(n, 0);

    for(int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        arr[i] = tmp;
    }

    sort(arr.begin(), arr.end());

    int st = 0, en = n-1, cnt = 0;
    while(st < en) {
        int sum = arr[st] + arr[en];
        if(sum > m) en--;
        else if(sum < m) st++;
        else {
            cnt++;
            st++;
            en--;
        }
    }
    cout << cnt;
}