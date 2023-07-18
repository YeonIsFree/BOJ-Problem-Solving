#include <bits/stdc++.h>
using namespace std;

int cnt;

int solution(vector<int> number) {
    sort(number.begin(), number.end());
    for(int i = 0; i < number.size(); i++) {
        for(int j = i+1; j < number.size(); j++) {
            int target = -(number[i] + number[j]);
            cnt += upper_bound(number.begin() + j + 1, number.end(), target) - lower_bound(number.begin()+j+1, number.end(), target);
        }
    }
    
    return cnt;
}