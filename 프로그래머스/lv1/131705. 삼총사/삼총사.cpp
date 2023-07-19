#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(), number.end());
    
    int len = number.size();
    for(int i = 0; i < len - 1; i++) {
        for(int j = i+1; j < len; j++) {
            int target = -(number[i] + number[j]);
            auto upper_it = upper_bound(number.begin() + j + 1, number.end(), target);
            auto lower_it = lower_bound(number.begin() + j + 1, number.end(), target);
            answer += upper_it - lower_it;
        }
    }
    return answer;
}