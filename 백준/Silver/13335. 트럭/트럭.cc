#include <bits/stdc++.h>
using namespace std;

int n, w, l;
int trucks[1002];    // 트럭들
queue<int> bridge; // 다리 상황을 나타내는 배열
int sum;    // 현재 다리 위 트럭들의 무게
int sec;

int main(void) {
    ios::sync_with_stdio(0);
    using namespace std;

    // 입력
    cin >> n >> w >> l;
    for(int i = 0; i < n; i++)
        cin >> trucks[i];

    // ----
    for(int i = 0; i < n; i++) {
        // 현재 보고 있는 트럭 무게
        int t = trucks[i]; 

        while(1) {
            // 다리를 한 칸씩 밀어준다.
            if(bridge.size() == w) {
                sum -= bridge.front();
                bridge.pop();
            }

            // 다리에 진입할 수 있을 경우
            if(sum + t <= l) break;

            // 다리에 진입할 수 없을 경우
            bridge.push(0);
            sec++;
        }

        bridge.push(t);
        sum += t;
        sec++;
    } // 모든 트럭 통과 완료

    // 마지막 트럭이 트럭에 진입 ~ 통과 하는 시간(w)을 더해준다.
    cout << sec + w;

}