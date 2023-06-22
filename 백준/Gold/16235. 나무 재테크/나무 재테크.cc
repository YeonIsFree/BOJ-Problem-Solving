#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

vector<int> tree[12][12];
int n, m, k;
int board[12][12]; // 상도의 땅 (양분)
int a[12][12]; // 겨울에 추가 될 양분의 양

void spring_summer() {
    // 모든 나무가 나이만큼 양분을 먹는다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tree[i][j].size() == 0) continue;
    
            sort(tree[i][j].begin(), tree[i][j].end()); 
            
            int die_sum = 0;
            vector<int> tmp;

            for(int age : tree[i][j]) {
                if(board[i][j] < age) {
                    die_sum += (age / 2);
                    continue;            
                }
                board[i][j] -= age;
                tmp.push_back(age + 1);
            }

            tree[i][j].clear();
            for(int t = 0; t < tmp.size(); t++)
                tree[i][j].push_back(tmp[t]);
            board[i][j] += die_sum;
        } 
    }
}

void fall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tree[i][j].size() == 0) continue;
            for(int age : tree[i][j]) {
                if(age % 5 != 0) continue;
                for(int dir = 0; dir < 8; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    tree[nx][ny].push_back(1);
                } 
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] += a[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            board[i][j] = 5;
        }
    }
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x-1][y-1].push_back(z);
    }

    for(int i = 0; i < k; i++) {
        spring_summer();
        fall();
        winter();
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tree[i][j].size() == 0) continue;
            cnt += tree[i][j].size();
        }
    }

    cout << cnt;

}