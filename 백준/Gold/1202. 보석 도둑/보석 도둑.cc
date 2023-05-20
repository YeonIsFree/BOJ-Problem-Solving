#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> j[300003]; // <val, m>
multiset<int> bags;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> j[i].second >> j[i].first;

    sort(j, j+n);

    for(int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        bags.insert(tmp);
    }
    // 가장 가치가 높은 보석부터 보면서
    // 해당 보석의 무게를 감당할 수 있는 가방을 찾는다.
    long long ans = 0;
    for(int i = n-1; i >= 0; i--) {
        int m, v;
        tie(v, m) = j[i];
        auto it = bags.lower_bound(m);
        if(it == bags.end()) continue;
        ans += v;
        bags.erase(it);
    }

    cout << ans;

}