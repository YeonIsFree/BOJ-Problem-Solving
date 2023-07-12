#include <bits/stdc++.h>
using namespace std;

bool is_in[10];
int sum = 0;

int solution(vector<int> numbers) {
    for(int target : numbers)
        is_in[target]  = true;
    for(int i = 0; i < 10; i++) {
        if(is_in[i]) continue;
        sum += i;
    }
    return sum;
}