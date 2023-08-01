#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) answer.push_back(i);
        while(n % i == 0) n /= i;
    }

    
    return answer;
}