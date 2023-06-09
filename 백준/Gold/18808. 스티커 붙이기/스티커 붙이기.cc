#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int laptop[42][42];
int sticker[12][12];

// 노트북의 각 칸에 스티커를 붙일 수 있는지 확인하는 함수
bool is_pastable(int x, int y) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(sticker[i][j] == 1 && laptop[x+i][y+j] == 1) return false;
    return true;
}

// 스티커를 붙이는 함수
void past_sticker(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(sticker[i][j] == 1) 
                laptop[x+i][y+j] = 1;
        }
    }
}

void rotate() {
    int tmp[12][12];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            sticker[i][j] = tmp[r-1-j][i];
    }
    swap(r, c);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
    
        // 스티커 입력 받기
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) 
                cin >> sticker[i][j];
        
        // 스티커를 붙일 수 있는지 확인 후 붙인다(1로 만든다.) 만약 붙일 수 없다면 돌려본다.
        for(int rot = 0; rot < 4; rot++) {
            bool ispasted = false;
            for(int x = 0; x <= n-r; x++) {
                if(ispasted) break;
                for(int y = 0; y <= m-c; y++) {
                    // 붙일 수 있다면
                    if(is_pastable(x, y)) {
                        past_sticker(x, y);
                        ispasted = true;
                        break;
                    }
                }
            }
            if(ispasted) break;
            rotate();
        }

    } // 모든 스티커 완료

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(laptop[i][j]) cnt++;
        }
    }
    cout << cnt;
}