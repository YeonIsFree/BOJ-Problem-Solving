#include <bits/stdc++.h>
using namespace std;

int tmp;
int ans;

string convert_to_binary(int num) {
    string ret = "";
    while(num > 0) {
        ret += to_string(num % 2);
        num /= 2;
    }
    return ret;
}

int solution(int n) {
    int target = n;
    while(1) {
        
        // 현재 숫자를 string 타입 이진수로 변환한다.
        string binary_n = convert_to_binary(target);
        
        // 1의 갯수를 세어준다.
        int cnt = 0;
        for(char c : binary_n)
            if(c == '1') cnt++;
        
        // n의 1의 갯수 저장
        if(target == n) {
            tmp = cnt;
            target++;
            continue;
        }
        
        // 1의 갯수가 같다면 종료
        if(cnt == tmp) {
            ans = target;
            break;
        }
        
        target++;
    }
    
    return ans;
}