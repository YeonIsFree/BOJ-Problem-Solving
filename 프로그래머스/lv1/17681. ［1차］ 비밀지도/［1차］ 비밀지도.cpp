#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

string convert_to_binary(int num, int n) {
    string tmp = "";
    string ret = "";
    while(num > 0) {
        tmp += to_string(num % 2);
        num /= 2;
    }
    reverse(tmp.begin(), tmp.end());
    int len = tmp.size();
    if(len < n) {
        int repeat = n - len;
        while(repeat--) ret += '0';
    }
    ret += tmp;
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    for(int i = 0; i < n; i++) {
        // 각 행에 나온 숫자를 이진법 string으로 변환한다.
        string binary_num1 = convert_to_binary(arr1[i], n);
        string binary_num2 = convert_to_binary(arr2[i], n);
        
        // 둘 중에 하나라도 벽(#, 1)이면 벽, 둘 다 빈 칸(' ', 0) 이면 빈 칸
        string tmp = "";
        for(int j = 0; j < n; j++) {
            if(binary_num1[j] == '1' || binary_num2[j] == '1') tmp += '#';
            else tmp += ' ';
        }
        
        ans.push_back(tmp);
    }
    return ans;
}