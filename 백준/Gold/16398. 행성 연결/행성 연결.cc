#include <bits/stdc++.h>
using namespace std;

int n;
int p[1003];
vector<tuple<int, int, int> > edge(1003);

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if(i >= j) continue;
            edge.push_back({cost, i, j}); // {비용, 출발노드, 도착노드}
        }
    }

    for(int i = 0; i < n; i++) p[i] = i;

    sort(edge.begin(), edge.end());

    long long sum = 0;
    int cnt = 0;
    for(int i = 0; i < edge.size(); i++) {
        int cost, st, en;
        tie(cost, st, en)= edge[i];
        if(!is_diff_group(st, en)) continue;
        cnt++;
        sum += cost;
        if(cnt == n-1) break;
    }
    cout << sum;
}