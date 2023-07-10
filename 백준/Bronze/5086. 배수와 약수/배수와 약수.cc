#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        int a = 0, b = 0;
        cin >> a >> b;
        if(a == 0 && b == 0) break;

        // 1) a가 b의 약수인지 판별
        if(b % a == 0) {
            cout << "factor\n";
            continue;
        }

        // 2) a가 b의 배수인지 판별
        if(a % b == 0) {
            cout << "multiple\n";
            continue;
        }

        // 3) 둘 다 아닌 경우
        cout << "neither\n";  
    }
}