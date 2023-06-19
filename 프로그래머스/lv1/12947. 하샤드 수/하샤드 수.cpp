#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    // 자릿수의 합 구하기
    int div = 0, tmp = x;
    while(tmp > 0) {
        div += (tmp % 10);
        tmp /= 10;
    }
    
    // 하샤드 수 판별
    if(x % div == 0) answer = true;
    else answer = false;
    
    return answer;
}