#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    (num1 == num2)? answer = 1 : answer = -1;
    return answer;
}