#include <bits/stdc++.h>
using namespace std;

int target, cnt;
vector<int> primes;

bool isprime(int num) {
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> target; 
    // n 을 연속된 소수의 합으로 나타낼 수 있는 경우의 수 찾기

    // n 이하 소수들을 벡터로 담아 둔다.
    for(int i = 1; i <= target; i++)
        if(isprime(i)) primes.push_back(i);
    
    if(primes.size() == 0) {
        cout << 0;
        return 0;
    }
    
    // primes 배열에서 부분 합을 구해서 n 이 나오는 경우의 수를 세어준다.
    int en = 0, len = primes.size(), sum = primes[0];
    for(int st = 0; st < len; st++) {
        while(sum < target && en < len) {
            en++;
            if(en != len) sum += primes[en];
        }
        // 여기 왔다는 것은 
        // sum >= target or en == len 이라는 것 
        if(en == len) break;
        if(sum == target) cnt++;
        sum -= primes[st];
    }
    cout << cnt;
}