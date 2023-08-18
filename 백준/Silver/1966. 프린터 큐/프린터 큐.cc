#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        priority_queue<int> P;
        queue<pair<int, int>> Q;
        vector<int> ans;

        cin >> n >> m;
        
        for(int i = 0; i < n; i++) {
            int priority = 0;
            cin >> priority;
            P.push(priority);       
            Q.push({i, priority});  
        }

        while(!Q.empty()) {
            int doc_num = Q.front().first;
            int priority = Q.front().second;
            
            if(priority == P.top()) {
                P.pop();
                ans.push_back(doc_num);
            }
            else
                Q.push({doc_num, priority});

            Q.pop();
        }

        for(int i = 0; i < ans.size(); i++)
            if(ans[i] == m) cout << i + 1 << '\n';   
    }
}