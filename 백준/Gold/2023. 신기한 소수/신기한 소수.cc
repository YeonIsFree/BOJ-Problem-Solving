#include <bits/stdc++.h>
using namespace std;

int n;

bool isprime(int n) {
    if(n == 1) return false;

    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;

    return true;   
}

void dfs(int num, int digit) {
    // n자리에 도달했다면 소수인지 검사하고 출력해준다.
    if(digit == n) {
        if(isprime(num)) cout << num << '\n';
        return;
    }

    // 한자리씩 붙여주고 만약 붙인 숫자가 소수라면
    // 한자리 더 붙여준다 (dfs 함수 재귀)
    for(int i = 1; i < 10; i++) {
        if(i % 2 == 0) continue; // 짝수이면 건너뛴다.
        int target = num * 10 + i;
        if(isprime(target)) 
            dfs(target, digit + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    int init[4] = {2, 3, 5, 7};
    for(int i : init)
        dfs(i, 1);
    
}