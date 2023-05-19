#include <bits/stdc++.h>
using namespace std;

int n, vis_cnt;
int arr[13]; // 각 구역의 인구 수
int area[13]; // 0 or 1로 선거구 표시 하는 배열
bool vis[13];
int ans = 0x7f7f7f7f;
vector<vector<int> > adj(13);

void bfs(int idx) {
    int area_code = area[idx];
    queue<int> Q;
    Q.push(idx);
    vis[idx] = 1;
    vis_cnt++;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            // 이미 방문한 구역이거나 구역 번호가 다를 경우 패스
            if(vis[nx] || area[nx] != area_code) continue;
            vis[nx] = 1;
            Q.push(nx);
            vis_cnt++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // n 입력
    cin >> n;
    // 각 구역의 인구수 입력
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    // 인접 도시 정보 입력
    for(int i = 1; i <= n; i++) {
        int t = 0;
        cin >> t;
        while(t--) {
            int num = 0;
            cin >> num;
            adj[i].push_back(num);
        }
    }

    // 모든 경우의 수에 대하여, 연결된 같은 선거구들을 세어준다.
    for(int i = 1; i < (1 << n)-1; i++) {
        // 초기화
        vis_cnt = 0;
        fill(vis, vis+n, 0);
        fill(area, area+n, 0);

        // 비트마스킹 이용하여 area 배열에 구역 나누어 표시
        int idx_0 = 0, idx_1 = 0;
        for(int j = 0; j < n; j++) {
            // j 구역이 1 선거구인 경우
            if(i & (1 << j)) {
                area[j+1] = 1;
                idx_1 = j + 1;              
            }
            else idx_0 = j + 1;
        } // 이번 구역 조합에서의 작업 종료

        // 위에서 받은 idx들로 각각 BFS 돌리기
        bfs(idx_1);
        bfs(idx_0);
        
        // 만약 BFS를 다 돌고 난 뒤 vis_cnt가 원래 구역 수 만큼 안나온다면,
        // 구역이 잘 나눠지지 못했다는 뜻이므로 다음 조합으로 넘어간다.
        if(vis_cnt != n) continue;

        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            if(area[i]) tmp += arr[i];
            else tmp -= arr[i];
        }
        tmp = abs(tmp);
        ans = min(tmp, ans);
    } // 구역을 나누는 모든 경우의 수 탐색 종료

    if(ans == 0x7f7f7f7f) {
        cout << -1;
        return 0;
    }

    cout << ans;
 
}