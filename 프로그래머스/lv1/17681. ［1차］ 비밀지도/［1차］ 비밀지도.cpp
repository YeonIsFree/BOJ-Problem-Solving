#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        // 두 지도의 각 행을 합하여 새로운 행을 만들어낸다.
        int new_row = arr1[i] | arr2[i];
        
        // 현재 행을 나타내는 10진법 수를 2진으로 변환하며 '#' 또는 ' '로 표기한다.
        string tmp = "";
        for(int j = 0; j < n; j++) {
            (new_row % 2)? tmp += '#' : tmp += ' ';
            new_row /= 2;
        }
        
        // 현재 만들어진 문자열 tmp 는 뒤집어진 상태라서 reverse 해준다.
        reverse(tmp.begin(), tmp.end());
        
        // '#', ' '로 이루어진 새로운 행을 정답 배열에 넣어준다.
        answer.push_back(tmp);
    }
    
    return answer;
}