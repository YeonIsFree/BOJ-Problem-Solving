#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; // 0x7f7f7f7f 를 쓰면 INF + INF 에서 Int overflow 발생
int n, m;
int d[103][103]; // i에서 j까지의 비용을 입력할 이차원 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // d 배열 무한대로 초기화
    for(int i = 1; i <= n; i++)
        fill(d[i] + 1, d[i] + 1 + n, INF);
    
    // 이차원 배열에 직행 최단 거리 입력
    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        d[a][b] = min(cost, d[a][b]);  // 같은 목적지에 여러 경로가 있을 수 있으므로 min()으로 넣어줘야 한다.
    }
    
    // 자기 자신으로 가는 거리는 비용을 0으로 만든다.
    for(int i = 1; i <= n; i++) d[i][i] = 0;

    // 중간에 거쳐갈 원소를 3중 for문의 제일 바깥쪽에 배치
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min((d[i][k] + d[k][j]), d[i][j]);
    
    // 답 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == INF) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}