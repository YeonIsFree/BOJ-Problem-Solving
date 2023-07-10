#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    string ans = "";
    for(int i = 0; i < seoul.size(); i++) {
        if(seoul[i] == "Kim") {
            string str_idx = to_string(i);
            ans = "김서방은 " + str_idx + "에 있다";
        }
    }
    return ans;
}