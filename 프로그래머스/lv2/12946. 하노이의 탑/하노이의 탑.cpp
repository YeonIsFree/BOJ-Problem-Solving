#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

void func(int a, int b, int n) {
    if(n == 1) {
        vector<int> tmp = {a, b};
        answer.push_back(tmp);
        return;
    }
    
    // n-1개의 원판을 6-a-b번 기둥으로 옮긴다.
    func(a, 6-a-b, n-1);
    // n번 원판을 목적지에 가져다 놓는다.
    vector<int> tmp = {a, b};
    answer.push_back(tmp);
    // 6-a-b번 기둥에 있던 원판들을 목적지로 옮긴다.
    func(6-a-b, b, n-1);
} 

vector<vector<int>> solution(int n) {

    func(1, 3, n); 
    
    return answer;
}