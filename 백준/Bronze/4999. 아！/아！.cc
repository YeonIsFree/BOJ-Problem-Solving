#include <bits/stdc++.h>
using namespace std;

string a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    // 의사가 요구하는 a의 갯수 구하기
    int target = 0;
    for(int i = 0; i < b.size(); i++)
        if(b[i] == 'a') target++;
    // 재환이의 a 갯수 측정
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == 'a')  ans++;
    
    // 판단
    if(target <= ans) cout << "go";
    else cout << "no";
}