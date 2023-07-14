#include <bits/stdc++.h>
using namespace std;

int zero_total;    // 제거한 모든 0의 개수
int cnt;           // 변환 진행 횟수
vector<int> ans;   

vector<int> solution(string s) {
    string target = s;
   while(target != "1") {
       // 변환 횟수를 올려준다.
       cnt++;
       
       // 제거할 0의 개수 세어주기
       int zero = 0;
       string tmp = "";
       for(char c : target) {
           if(c == '0') {
               zero++;
               continue;
           }
           else tmp += c;
       }
       zero_total += zero;
       
       // 0 제거 후 길이를 이진 변환
       int len = tmp.size();
       target = "";
       while(len > 0) {
           target += to_string(len % 2);
           len /= 2;
       }
   }
    
    ans.push_back(cnt);
    ans.push_back(zero_total);
    
    return ans;
    
}