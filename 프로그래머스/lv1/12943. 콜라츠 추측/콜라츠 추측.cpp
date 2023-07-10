#include <bits/stdc++.h>
using namespace std;

int solution(int num) {
    long long n = num;
    int cnt = 0;
    int ans = 0;
    
    if(n == 1) return 0;
    
    while(cnt <= 500) {
        cnt++;
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        
        if(n == 1) return cnt;
    }
    
    if(cnt > 500 && n != 1) return -1;
    
}