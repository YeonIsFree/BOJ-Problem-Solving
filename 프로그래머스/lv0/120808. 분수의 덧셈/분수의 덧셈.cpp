#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int denom = denom1 * denom2; // 분모
    int numer = numer1 * denom2 + numer2 * denom1; // 분자
    int tmp = gcd(denom, numer);
    
    answer.push_back(numer / tmp);
    answer.push_back(denom / tmp);
    return answer;
}