#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p_cnt = 0;
    int y_cnt = 0;
    
    for(char c : s) {
        if(c == 'p' || c == 'P') p_cnt++;
        else if(c == 'y' || c == 'Y') y_cnt++;
    }
    
    if(p_cnt == y_cnt) answer = true;
    
    else answer = false;

    return answer;
}