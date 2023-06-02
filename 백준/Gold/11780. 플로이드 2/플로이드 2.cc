#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[103][103];
int nx[103][103]; // 최단 거리로 가려면 출발로부터 어느 정점으로 가야하는지 저장하는 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        fill(d[i], d[i] + 1 + n, INF);

    for(int i = 1; i <= m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        d[a][b] = min(cost, d[a][b]);
        nx[a][b] = b; 
    }

    for(int i = 1; i <= n; i++) d[i][i] = 0;

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // 만약 현재 저장되어 있는 비용보다 더 낮은 비용의 경로가 있다면
                if(d[i][j] > (d[i][k] + d[k][j])) {
                    d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }

    // 최단 거리 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == INF) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    // 경로 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 갈 수 없는 경우 혹은 자기 자신으로 가는 경우엔 0을 출력
            if(d[i][j] == 0 || d[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }

            vector<int> ans;
            
            int st = i;
            while(st != j) {
                ans.push_back(st);
                st = nx[st][j];
            }
            ans.push_back(j);

            cout << ans.size() << ' ';
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
            cout << '\n';            
        }
    }
}