#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int len = s.size();
    int mid = len / 2;
    
    if(len % 2 == 0) return s.substr(mid-1, 2);
    else return s.substr(mid, 1);
}