#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int GCD = gcd(a, b);
    b /= GCD;
    
    while(b % 2 == 0) b /= 2;
    while(b % 5 == 0) b /= 5;
    
    answer = (b == 1) ? 1 : 2;
    
    return answer;
}