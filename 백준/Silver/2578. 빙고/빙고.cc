#include <bits/stdc++.h>
using namespace std;

int board[7][7];
vector<int> nums;
int target;
bool ret;

bool check_bingo() {
    int cnt = 0;

    // row_check
    for(int i = 0; i < 5; i++) {
        bool row_check = true;
        if(board[i][0] != 0) continue;
        for(int j = 1; j < 5; j++)
            if(board[i][j] != 0) row_check = false;
        
        if(row_check) cnt++; 
    }

    // col_check
    for(int j = 0; j < 5; j++) {
        bool col_check = true;
        if(board[0][j] != 0) continue;
        for(int i = 1; i < 5; i++)
            if(board[i][j] != 0) col_check = false;
        
        if(col_check) cnt++;
    }

    // diagonal check
    if(board[0][0] == 0 && board[4][4] == 0) {
        bool diagonal_check = true;
        for(int i = 1; i < 4; i++)
            if(board[i][i] != 0) diagonal_check = false;
        
        if(diagonal_check) cnt++;
    }
    if(board[0][4] == 0 && board[4][0] == 0) {
        bool diagonal_check = true;
        for(int i = 1; i < 4; i++)
            if(board[i][4-i] != 0) diagonal_check = false;

        if(diagonal_check) cnt++;
    }

    if(cnt >= 3) return true;
    else return false;
}

void mark_board(int target) {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(board[i][j] == target) board[i][j] = 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < 25; i++) {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }

    //-----
    for(int i = 0; i < 25; i++) {
        int target = nums[i];
        // 1) target에 해당 칸을 칠한다.
        mark_board(target);

        // 2) 빙고 체크를 한다.
        ret = check_bingo();

        // 3) 만약 빙고라면 i+1 을 출력하고 종료
        if(ret) {
            cout << i+1;
            return 0;
        }
    }
}