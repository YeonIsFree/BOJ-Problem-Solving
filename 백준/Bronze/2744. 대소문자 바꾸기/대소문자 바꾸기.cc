#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for(char c : str) {
        // 대문자 -> 소문자
        if(c <= 'Z') cout << char(c + 32);

        // 소문자 -> 대문자
        else if(c >= 'a') cout << char(c - 32);
    }
}