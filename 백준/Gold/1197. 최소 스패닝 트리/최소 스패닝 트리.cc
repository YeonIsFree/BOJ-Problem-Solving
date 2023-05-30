#include <bits/stdc++.h>
using namespace std;

int v, e;
tuple<int, int, int> edge[100003];
vector<int> p(10005, -1);

// 부모 노드를 찾는 함수
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 두 부모 노드를 합치는 함수
bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    if(p[a] == p[b]) p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;  // p[a] > p[b]
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);

    int cnt = 0, sum = 0;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        sum += cost;
        cnt++;
        if(cnt == v-1) break;
    }

    cout << sum;

}