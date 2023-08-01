#include <bits/stdc++.h>
using namespace std;

bool isAlpha(string str) {
    for(char c : str)
        if(!islower(c)) return false;
    return true;
}

vector<string> func(string str) {
    vector<string> arr;
    for(int i = 0; i < str.size()-1; i++) {
        string tmp = str.substr(i, 2);
        if(!isAlpha(tmp)) continue;
        arr.push_back(tmp);
    }
    return arr;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    // 입력 문자열을 모두 소문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    // 두 글자씩 쪼개기 : 특수문자는 제거
    vector<string> arr1 = func(str1);
    vector<string> arr2 = func(str2);
    
    // 정렬
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    // 교집합 갯수 구하기
    vector<string> inter_v;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(inter_v));
    int inter_cnt = inter_v.size();

    // 합집합 갯수 구하기
    vector<string> union_v;
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(union_v));
    int union_cnt = union_v.size();

    // 자카드 유사도 계산
    float div = (union_cnt == 0) ? 1 : (float)inter_cnt / (float)union_cnt;
    answer = div * 65536;
    
    return answer;
}