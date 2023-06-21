#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    queue<int> Q;
    for(int i = 1; i <= n; i++) Q.push(i);

    while(Q.size() > 0) {
        for(int i = 0; i < k-1; i++) {
            int target = Q.front(); 
            Q.push(target);
            Q.pop();
        }

        ans.push_back(Q.front());
        Q.pop();
    }

    cout << "<";
    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[n-1] << ">"; 

}