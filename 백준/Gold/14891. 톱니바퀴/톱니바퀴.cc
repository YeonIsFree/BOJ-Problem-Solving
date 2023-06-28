#include <bits/stdc++.h>
using namespace std;

vector<string> gears(4);
vector<int> dirs(4);
int k;
int num, d;

void run() {
    for(int i = 0; i < 4; i++) {
        // 반시계 방향 회전
        if(dirs[i] == -1) rotate(gears[i].begin(), gears[i].begin()+1, gears[i].end());
        // 시계 방향 회전
        else if(dirs[i] == 1) rotate(gears[i].begin(), gears[i].begin()+7, gears[i].end());
    }
}

void dir_check(int num) {
    // num 번 기어를 중심으로 왼쪽 진행
    int idx = num;
    while(idx > 0 && gears[idx][6] != gears[idx - 1][2]) {
        dirs[idx - 1] = -dirs[idx];
        idx--;
    }

    // num 번 기어를 중심으로 오른쪽 진행
    idx = num;
    while(idx < 3 && gears[idx][2] != gears[idx + 1][6]) {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 4; i++) cin >> gears[i];
    cin >> k;
    while(k--) {
        int tmp;
        cin >> tmp >> d;

        num = tmp - 1;
        
        fill(dirs.begin(), dirs.end(), 0);

        // 1) 먼저 num 번 톱니 바퀴를 중심으로 각 톱니 바퀴들의 회전 방향을 결정한다.
        dirs[num] = d;
        dir_check(num);

        // 2) 위에서 결정된 방향으로 각 톱니 바퀴들을 돌린다.
        run();
    }
        // 3) 점수를 계산한다.
    int score = 0;
    for(int i = 0; i < 4; i++)
        if(gears[i][0] == '1') score += (1 << i);
    
    cout << score;
    
}