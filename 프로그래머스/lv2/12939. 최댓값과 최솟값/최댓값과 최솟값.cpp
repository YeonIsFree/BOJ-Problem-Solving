#include <bits/stdc++.h>
using namespace std;

vector<int> tmp;
string target;

string solution(string s) {
    vector<int> tmp;
    string target = "";
    int len = s.size();
    
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') {
            tmp.push_back(stoi(target));
            target = "";
        }
        
        if(i == len - 1) {
            target += s[i];
            tmp.push_back(stoi(target));
        }
        
        target += s[i];
     
    }
    
    string mn = to_string(*min_element(tmp.begin(), tmp.end()));
    string mx = to_string(*max_element(tmp.begin(), tmp.end()));
    
    return mn + " " + mx;
}