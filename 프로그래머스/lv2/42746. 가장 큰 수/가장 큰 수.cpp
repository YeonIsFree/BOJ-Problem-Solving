#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    if(a + b > b + a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    vector<string> strs;
    
    // 숫자들을 문자열로 변환하여 strs 배열에 넣어준다.
    for(int i : numbers) strs.push_back(to_string(i));
    
    // a + b 와 b + a 조합 중 사전 순으로 큰 순으로 sorting 
    sort(strs.begin(), strs.end(), cmp);
    
    // ans에 하나씩 붙여서 출력해준다.
    string ans = "";
    for(string str : strs) ans += str;
    
    if(ans[0] == '0') ans = '0';
         
    return ans;
}