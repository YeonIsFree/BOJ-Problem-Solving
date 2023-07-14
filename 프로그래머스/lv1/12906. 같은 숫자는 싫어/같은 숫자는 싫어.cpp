#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    queue<int> Q;
    for(int i : arr) {
        if(Q.empty()) {
            Q.push(i);
            continue;
        }
        
        if(i == Q.back()) continue;
        Q.push(i);
    }
    
    while(!Q.empty()) {
        ans.push_back(Q.front());
        Q.pop();
    }
    
    return ans;
}