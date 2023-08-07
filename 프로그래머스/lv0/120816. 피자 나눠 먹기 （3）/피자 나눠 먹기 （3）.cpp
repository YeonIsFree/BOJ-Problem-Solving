#include <bits/stdc++.h>
using namespace std;

int solution(int slice, int n) {
    if(n % slice == 0) return n / slice;
    else if(n % slice > 0) return n / slice + 1;
}