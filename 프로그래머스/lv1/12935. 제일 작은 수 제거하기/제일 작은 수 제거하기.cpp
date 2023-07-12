#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tmp = arr;
    
    // 입력으로 들어오는 배열 길이가 1일 경우 -1 리턴
    if(arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    // 최솟값 mn 찾기
    sort(tmp.begin(), tmp.end());
    int mn = tmp[0];
    
    // 최솟값 mn을 제외한 숫자를 차곡차곡 answer에 쌓는다.
    for(int num : arr) {
        if(num == mn) continue;
        answer.push_back(num);
    }
    
    return answer;
}