#include <bits/stdc++.h>
using namespace std;

int n;
int fibo[22];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    
    fibo[0] = 0, fibo[1] = 1;
    for(int i = 2; i <= n; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    cout << fibo[n];
    
}