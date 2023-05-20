#include <bits/stdc++.h>
using namespace std;

int t, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> k;
        multiset<int> Q;
        while(k--) {
            char com;
            cin >> com;
            if(com == 'D') {
                int num;
                cin >> num;
                if(Q.empty()) continue;
                if(num == 1) Q.erase(prev(Q.end()));
                else if(num == -1) Q.erase(Q.begin());
            }
            else { // com == 'I'
                int num;
                cin >> num;
                Q.insert(num);
            }
        } // 한 테스트 케이스 종료

        if(Q.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(Q.end()) << ' ' << *(Q.begin()) << '\n';
  
    } // 모든 테스트 케이스 종료
}