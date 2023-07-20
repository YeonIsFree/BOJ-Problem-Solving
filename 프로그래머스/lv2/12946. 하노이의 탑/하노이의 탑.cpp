#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

void func(int a, int b, int n) {
    if(n == 1) { 
        vector<int> tmp = {a, b};
        ans.push_back(tmp);
        return;
    }
    // 1) a 기둥에 있는 n-1개의 원판을 6-a-b 기둥으로 옮겨준다.
    func(a, 6-a-b, n-1);
    // 2) a 기둥에 있는 n번 원판을 b 기둥으로 옮겨준다.
    vector<int> tmp = {a, b};
    ans.push_back(tmp);
    // 3) 6-a-b 기둥에 있는 n-1개의 원판을 b 기둥으로 옮겨준다.
    func(6-a-b, b, n-1);
}

vector<vector<int>> solution(int n) {
    func(1, 3, n);
    
    return ans;
}