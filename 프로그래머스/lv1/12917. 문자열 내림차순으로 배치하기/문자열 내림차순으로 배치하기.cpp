#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string tmp = s;
    sort(tmp.begin(), tmp.end(), greater());
    
    string ans = "";
    for(char c : tmp) ans += c;
    
    return ans;
}