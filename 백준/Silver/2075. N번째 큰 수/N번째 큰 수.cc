#include <bits/stdc++.h>
using namespace std;

int n, tmp;
priority_queue<int, vector<int>, greater<int>> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n*n; i++) {
        cin >> tmp;
        if(Q.empty() || Q.size() < n) Q.push(tmp);
        if(Q.size() >= n && (tmp > Q.top())) {
            Q.pop();
            Q.push(tmp);
        }    
    }

    while(Q.size() == 1) Q.pop();
    cout << Q.top();
}