#include <bits/stdc++.h>
using namespace std;

int n, q;
set<int> isfamous; // 명소인 구역 번호 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) continue;
        isfamous.insert(i);
    }    
    
    // 명령어 수행
    int now = 0;  // 현재 위치
    for(int i = 0; i < q; i++) {

        int com;
        cin >> com;
        if(com == 1) {
            int i;
            cin >> i;
            // 명소 리스트에 이미 있으면 지우고
            if(isfamous.find(i-1) != isfamous.end()) 
                isfamous.erase(i-1);  
            else // 없으면 추가
                isfamous.insert(i-1);
        }
        else if(com == 2) {
            int x;
            cin >> x;
            now = (now + x) % n;
        }
        else if(com == 3) {
            if(isfamous.empty()) cout << -1 << '\n';
            else {
                // for(int i : isfamous)
                //     cout << i << ' ';
                // cout << '\n';
                auto it = isfamous.lower_bound(now);
                // 넣을데가 없으면(맨 뒤면) <-- 이걸 간과함
                if(it == isfamous.end()) cout << n - now + *isfamous.begin() << '\n';
                else{
                    cout << *it - now << '\n';
                }
            }
        }
    }
}