#include <bits/stdc++.h>
using namespace std;

int n;
int mp, mf, ms, mv;
vector<int> p, f, s, v, price;
vector<int> temp;
vector<int> ans;
map<int, vector<vector<int>>> ans_candi;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        cin >> a >> b >> c >> d >> e;
        p.push_back(a);
        f.push_back(b);
        s.push_back(c);
        v.push_back(d);
        price.push_back(e);
    }

    int mn_price = 98765;
    for(int i = 1; i < (1 << n); i++) {
        int p_sum = 0, f_sum = 0, s_sum = 0, v_sum = 0, price_sum = 0;
        temp.clear();
        for(int j = 0; j < n; j++) {
            if(!(i & (1 << j))) continue;
            temp.push_back(j);
            p_sum += p[j];
            f_sum += f[j];
            s_sum += s[j];
            v_sum += v[j];
            price_sum += price[j];
        }

        if(p_sum < mp || f_sum < mf || s_sum < ms || v_sum < mv) continue;
        if(mn_price < price_sum) continue;
        mn_price = price_sum;
        ans_candi[mn_price].push_back(temp);
    }
    
    if(mn_price == 98765) {
        cout << -1 << '\n';
        return 0;
    }
    
    sort(ans_candi[mn_price].begin(), ans_candi[mn_price].end());

    cout << mn_price << '\n';

    for(int i : ans_candi[mn_price][0])
        cout << i + 1 << ' ';

}