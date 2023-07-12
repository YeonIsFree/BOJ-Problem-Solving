#include <string>
#include <vector>

using namespace std;

// 약수의 개수를 찾는 함수
int div(int n) {
    int cnt = 0;
    // 약수를 셀 때 1부터 해당 숫자의 절반까지만 찾아주면 
    // 나머지는 쌍으로 구해줄 수 있다.
    // 예를 들어, 18의 약수를 찾을 때 약수 2를 찾았으면 9도 쌍으로 찾을 수 있으니 +2개 해주는 식.
    for(int i = 1; i * i <= n; i++) {
        // 예외 : 제곱수인 경우는 1개만 세준다.
        if(i * i == n) cnt += 1;
        // 약수(나눠서 떨어지는 수)를 쌍으로 세어준다.
        if(n % i == 0) cnt += 2;
    }
    return cnt;
}

int solution(int left, int right) {
    int sum = 0;
    for(int i = left; i <= right; i++) {
        if(div(i) % 2 == 0) sum += i;
        else sum -= i;
    }
    
    return sum;
    
}