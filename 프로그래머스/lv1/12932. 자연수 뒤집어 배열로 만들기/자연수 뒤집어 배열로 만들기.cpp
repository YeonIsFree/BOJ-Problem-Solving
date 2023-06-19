#include <bits/stdc++.h>

using namespace std;

// 123456

vector<int> solution(long long n) {
    vector<int> answer;
    string num = to_string(n);
    reverse(num.begin(), num.end());
    for(char c : num) {
        int tmp = c - '0';
        answer.push_back(tmp);
    }
    
    
    
    return answer;
}