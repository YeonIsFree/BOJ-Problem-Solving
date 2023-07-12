#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    // 입력 배열의 길이가 1인 경우 -1을 리턴
    if(arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    // 최소값의 iterator 를 mn_it에 담고 erase 로 지워준다.
    answer = arr;
    auto mn_it = min_element(answer.begin(), answer.end());
    answer.erase(mn_it);
    return answer;
}

