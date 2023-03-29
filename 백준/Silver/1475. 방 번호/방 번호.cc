#include <bits/stdc++.h>
using namespace std;

int num;
int freq[10];
int ans = 1;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;

    while(num > 0){
        freq[num % 10]++;
        num /= 10;
    }
    
    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9) continue;
        ans = max(freq[i], ans);
    }

    ans = max(ans, (freq[6]+freq[9]+1)/2);
    cout << ans;

}