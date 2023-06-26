#include <bits/stdc++.h>
using namespace std;

int n, mx;
int board1[22][22]; // 입력받은 원본 보드
int board2[22][22];

void rotate() {
    int tmp_board[22][22];
    // tmp_board에 돌릴 보드를 복사하고
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp_board[i][j] = board2[i][j];
    // 90도 뒤집는다
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board2[i][j] = tmp_board[n-1-j][i];
}

void tilt(int dir) {
    // 해당 방향으로 보드를 돌린다.
    while(dir--) rotate();

    // 각 행에 대해서 왼쪽으로 민다.
    for(int i = 0; i < n; i++) {
        int tilted[22] = {}; // 기울인 후의 모습을 저장할 배열
        int idx = 0;         // tilted 배열에서 사용할 포인터
        for(int j = 0; j < n; j++) {
            if(board2[i][j] == 0) continue;

            if(tilted[idx] == 0) tilted[idx] = board2[i][j];
            else if(tilted[idx] == board2[i][j]) {
                tilted[idx] *= 2;
                idx++;
            }
            else {  // 값이 다를 경우
                idx++;
                tilted[idx] = board2[i][j];
            }
        }
        // 이제 행을 덮어쓴다.
        for(int j = 0; j < n; j++) board2[i][j] = tilted[j];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> board1[i][j];

    // 보드를 시계 방향으로 90도씩 돌려 왼쪽으로 이동시키면 된다.
    for(int tmp = 0; tmp < 1024; tmp++) {
        // 배열 복사
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        
        // 왼쪽 - 아래 - 오른쪽 - 위 --> 4진법으로 표기한다.
        // 3 0 1 2 2 : 위 왼 아래 오 오  
        int brute = tmp;
        // 4진법으로 변환시키는 부분
        for(int i = 0; i < 5; i++) { // 5회 반복한다.
            int dir = brute % 4;
            brute /= 4;
            // 회전된 보드를 왼쪽으로 이동 (각 방향으로 이동시키는 효과가 있다.)
            tilt(dir);
        }

        // 현재 경우의 수에서의 가장 큰 블록을 저장
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);

    } // 모든 경우의 수 탐색 완료

    // 모든 경우의 수를 고려한 가장 큰 블록 출력
    cout << mx;
}