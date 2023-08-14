#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int len = words.size();
    vector<int> answer;
    map<string, bool> isused;
    
    for(int i = 1; i < len; i++) {
        
        string prev_word = words[i-1];
        int prev_len = prev_word.size();
        string cur_word = words[i];
        
        isused[prev_word] = true;
       
        // 1) 시작 단어 검사
        if(prev_word[prev_len - 1] != cur_word[0]) {
            int player = i % n + 1;
            int cnt = i / n + 1;
            answer.push_back(player);
            answer.push_back(cnt);
            break;
        }
        
        // 2) 사용했던 단어 검사
        if(isused[cur_word] == true) {
            int player = i % n + 1;
            int cnt = i / n + 1;
            answer.push_back(player);
            answer.push_back(cnt);
            break;
        }
        
        // 3) 통과 한 단어는 기록해둔다.
        isused[cur_word] = true;
    }
    
    if(answer.size() == 0) {
        answer = {0, 0};
    }
    

    return answer;
}