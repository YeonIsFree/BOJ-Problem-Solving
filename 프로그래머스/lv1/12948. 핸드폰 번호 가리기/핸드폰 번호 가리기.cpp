#include <bits/stdc++.h>
using namespace std;

string solution(string phone_number) {
    string ans = phone_number;
    int len = phone_number.size();
    
    for(int i = 0; i < (int)len - 4; i++) 
            ans[i] = '*';
    
    return ans;

}