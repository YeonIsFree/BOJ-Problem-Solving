#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b % a, a);
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}


int solution(vector<int> arr) {
    int answer = 1;
    for(int i : arr)
        answer = LCM(answer, i);
    return answer;
}