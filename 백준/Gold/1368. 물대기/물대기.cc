#include <bits/stdc++.h>
using namespace std;

int n;
int p[303];
tuple<int, int, int> edge[100003];

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    if(p[a] > p[b]) p[a] = b;
    else p[b] = a;
    return true;
}

/*
    이 문제는 노드 자체에 비용 (우물 비용)이 존재해서 난해하다.
    이 문제를 MST로 풀기 위해 가상의 노드 하나를 추가하고, 
    노드 비용들과 같은 간선이 다른 노드들과 연결되어 있다고 생각한다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    // 입력
    cin >> n;
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        int cost = 0;
        cin >> cost;
        // n+1이라는 가상의 노드를 하나 추가하고 다른 노드들과 연결
        edge[idx++] = {cost, i, n+1};  // {비용, 출발노드, 도착노드}
    }

    // 간선 정도 입력 받기
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;
            if(i >= j) continue;
            edge[idx++] = {cost, i, j};
        }
    }

    // 오름차순 정렬 - 최소 비용을 구해야하므로
    sort(edge, edge + idx);
    
    // 유니온 파인드를 위한 p배열 초기화
    for(int i = 1; i <= n+1; i++) p[i] = i;

    // 다른 노드 하나를 추가해서 MST로 풀이 - 크루스칼 알고리즘 이용
    int cnt = 0, sum = 0;
    for(int i = 0; i <= idx; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        // 서로 다른 그룹이면 넘어간다.
        if(!is_diff_group(a, b)) continue;
        cnt++;
        sum += cost;
        // 원래라면 cnt == n-1 이지만,
        // 지금은 노드 수를 하나 더 추가해서 생각하고 있는 상태이므로 cnt == n이다.
        if(cnt == n) break;
    }
    cout << sum;
}