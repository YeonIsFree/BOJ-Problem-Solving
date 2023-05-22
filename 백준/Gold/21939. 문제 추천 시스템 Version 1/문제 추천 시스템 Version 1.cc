#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<pair<int, int> > p; // <난이도, 문제번호>
map<int, int> level; // 문제의 레벨을 따로 저장해둘 map

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 추천 문제 리스트 입력, 문제 레벨은 따로 map에 저장해둔다.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int pnum, l;
        cin >> pnum >> l;
        p.insert({l, pnum});
        level[pnum] = l;
    }

    // 명령문 입력
    cin >> m;
    for(int i = 0; i < m; i++) {
        string com;
        cin >> com;
        if(com == "recommend") {
            int num;
            cin >> num;
            if(num == 1) 
                cout << prev(p.end())->second << '\n';
            else // nim == -1
                cout << p.begin()->second << '\n';
        }
        else if(com == "solved") {
            int pnum;
            cin >> pnum;
            if(p.empty()) continue;
            // 문제 난이도를 따로 저장해둔 배열로 가서 난이도를 불러온다.
            int lev = level[pnum];
            p.erase({lev, pnum});
        }
        else if(com == "add") {
            int pnum, l;
            cin >> pnum >> l;
            p.insert({l, pnum});
        }
    }
}