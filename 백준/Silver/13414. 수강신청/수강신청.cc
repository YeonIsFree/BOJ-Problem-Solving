#include <bits/stdc++.h>
using namespace std;

int k, l;  // k : 수강 가능 인원   l : 대기열 길이
unordered_map<string, int> Q;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> l;
    for(int i = 0; i < l; i++) {
        string id = "";
        cin >> id;

        // 이미 map에 존재하면, 기존 데이터 지웠다가 이번 순서로 다시 추가한다.
        if(Q.find(id) != Q.end()) {
            Q.erase(id);
            Q[id] = i;
        }
        // map에 없으면 추가
        Q[id] = i;
    }

    vector<pair<string, int> > id_list(Q.begin(), Q.end());
    // id_list 벡터의 second(value)값을 기준으로 정렬
    sort(id_list.begin(), id_list.end(), cmp);
    
    // 예외 처리) 신청한 학생이 수강 가능 인원보다 적을 수도 있다.
    if(id_list.size() < k) k = id_list.size();

    for(int i = 0; i < k; i++)
        cout << id_list[i].first << '\n';

}