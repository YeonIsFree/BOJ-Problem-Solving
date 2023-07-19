#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int cnt = bitset<20> (n).count();
    
    while(1) {
        if(bitset<20> (++n).count() == cnt)
            break;
    }
    
    return n;
}