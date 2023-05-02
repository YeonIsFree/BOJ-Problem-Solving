#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[55][55];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

// 입력 받으면서 치킨집 좌표, 집의 좌표를 각각 배열에 저장함.
// 최대 M개의 치킨집을 고르는 문제이지만, 그냥 M개 다 고르면 됨. 그게 이득임.
// M개를 고르는 모든 조합에 대해서, 각각의 치킨집과 집과의 치킨 거리를 정한다. 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i, j});
            if(board[i][j] == 2) chicken.push_back({i, j});
        }
    }
    
    // is_selected[i] 는 선택할 치킨집을 고르는 조합
    vector<int> is_selected(chicken.size(), 1);
    for(int i = 0; i < chicken.size()-m ; i++)
        is_selected[i] = 0;

    int ans = 9876;
    do {
        int sum = 0;
        for(auto h : house) {
            int mn_dist = 98765; // 이번 집이랑 제일 가까운(제일 작은) 치킨집이랑의 거리
            int dist = 0;
            for(int i = 0; i < chicken.size(); i++) {
                if(is_selected[i] == 0) continue;
                dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
                mn_dist = min(dist, mn_dist);
            }
            sum += mn_dist;
        }

        ans = min(ans, sum);
    } while(next_permutation(is_selected.begin(), is_selected.end()));

    cout << ans;
}