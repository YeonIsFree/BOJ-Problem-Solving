#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int lenT = t.size();
    int lenP = p.size();
    long long numP = stoll(p);
    
    for(int i = 0; i <= (int)(lenT - lenP); i++) {
        long long tmp = stoll( t.substr(i, lenP) );
        if(tmp <= numP) answer++;
    }
    
    return answer;
}