#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int height = 3; height * height <= sum; height++) {
        if(sum % height != 0) continue;
        int width = sum / height;
        
        int yellow_width = width - 2;
        int yellow_height = height - 2;
       
        if(yellow_width * yellow_height == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}