#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr(1003);
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) arr[i] = i;
    
    int idx = k;
    while(ans.size() != n) {
        ans.push_back(arr[idx]);
        arr[idx] = 0;
        int cnt = k;
        while(cnt--) {
            idx++;
            if(idx > n) idx = 1;
            if(ans.size() != n && arr[idx] == 0) cnt++;
        }
    }

    cout << "<";
    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i == n-1) break;
        cout << ", ";
    }
    cout << ">";

}