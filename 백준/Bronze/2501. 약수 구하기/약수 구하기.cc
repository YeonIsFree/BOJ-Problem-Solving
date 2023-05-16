#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ans;

void func(int n) {
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0) ans.push_back(i);
    for(int j = (int)ans.size() - 1; j >= 0; j--) {
        if(ans[j] * ans[j] == n) continue;
        ans.push_back(n / ans[j]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    func(n);

    if(ans.size() < k) {
        cout << 0;
        return 0;
    }

    cout << ans[k-1];
}