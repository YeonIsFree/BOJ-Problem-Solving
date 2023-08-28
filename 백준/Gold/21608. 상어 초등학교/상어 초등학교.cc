#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int student[402][5];      // 학생과 해당 학생의 BF 정보
int board[22][22];        // 좌석 배치
vector<int> BFArr[402];    // 각 학생들의 BFList을 저장해둔 배열

struct Info {
    int x;
    int y;
    int blank;  // 인접한 빈 칸의 수
    int BF;     // 인접한 좋아하는 친구의 수
};

bool cmp(Info a, Info b) {
    if(a.BF == b.BF) {
        if(a.blank == b.blank) {
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        }
        return a.blank > b.blank;
    }
    return a.BF > b.BF;
}

bool isBF(vector<int> BFList, int x, int y) {
    for(int i = 0; i < BFList.size(); i++)
        if(board[x][y] == BFList[i]) return true;
    return false;
}

int BFCounter(vector<int> BFList, int x, int y) {
    int ret = 0;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(isBF(BFList, nx, ny)) ret++;
    }
    return ret;
}

Info BFS(vector<int> BFList, int x, int y) {
    Info ret = { x, y, 0, 0 };
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        // 다음 칸이 빈칸인 경우 
        if(board[nx][ny] == 0) {
            ret.blank++;
            continue;
        }
        // 다음 칸이 현재 학생의 BF인 경우
        if(isBF(BFList, nx, ny)) {
            ret.BF++;
            continue;
        }
    }
    return ret;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n * n; i++)
        for(int j = 0; j < 5; j++)
            cin >> student[i][j];
 
    // 1. 모든 학생을 조건에 맞는 자리에 앉힌다.
    for(int k = 0; k < n * n; k++) {
        int target = student[k][0];  // 현재 보고 있는 학생

        vector<Info> tmp;            // 모든 칸의 정보를 담을 배열
        vector<int> BFList;          // 현재 학생의 BF 목록들
        
        // 0) 해당 학생의 BFList를 구한다. 
        for(int i = 1; i < 5; i++) BFList.push_back(student[k][i]);

        // +) 만족도 계산을 위해 해당 학생의 BFList를 따로 저장해둔다.
        BFArr[target] = BFList;

        // 1) 모든 칸을 조사하여 조건에 맞는 자리에 앉힌다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // 1-0) 이미 누가 앉았으면 패스
                if(board[i][j] != 0) continue;
                
                // 1-1) 해당 칸을 기준으로 상하좌우를 탐색해서 정보를 담는다.
                tmp.push_back(BFS(BFList, i, j));
            }
        }

        // 1-2) 내림차순 커스텀 정렬
        sort(tmp.begin(), tmp.end(), cmp);

        // 1-3) 제일 처음 자리에 앉힌다.
        board[tmp[0].x][tmp[0].y] = target;
    }

    // 2. 만족도 계산
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int target = board[i][j];           // 현재 보고 있는 학생
            vector<int> BFList = BFArr[target]; // 현재 학생의 BFList

            // 2-1) 인접한 칸에 좋아하는 학생의 수를 반환하는 함수
            int cnt = BFCounter(BFList, i, j);

            // 2-2) 계산
            if(cnt == 1) ans += 1;
            else if(cnt == 2) ans += 10;
            else if(cnt == 3) ans += 100;
            else if(cnt == 4) ans += 1000;
            else continue;
        }
    }

    // 3. 출력
    cout << ans;

}