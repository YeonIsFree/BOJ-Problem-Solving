#include <bits/stdc++.h>
using namespace std;

int n;

// priority_queue 는 cmp를 클래스로 짜야한다.
class cmp {
public:
    bool operator() (int a, int b) {
        if(abs(a) != abs(b)) 
            return abs(a) > abs(b); // 내림차순
        // 절댓값이 같은 경우 두 수가 다르고 앞이 양수, 뒤가 음수일 때에만 true를 반환
        return a > 0 && b < 0;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> PQ;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            if(PQ.empty()) cout << 0 << '\n';
            // 절댓값이 가장 작은 값을 출력하고
            // 그 뒤 값을 배열에서 제거
            else {
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        }
        else 
            PQ.push(x);
    }
}