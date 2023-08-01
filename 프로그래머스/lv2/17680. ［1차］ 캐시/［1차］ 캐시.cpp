#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache;
    for(string tmp : cities) {
        // 0) 예외 : cacheSize 가 0인 경우
        if(cacheSize == 0) {
            answer = cities.size() * 5;
            break;
        }
        // 1) 소문자 변환
        string city = "";
        for(char c : tmp) city += tolower(c);
        
        auto itr = find(cache.begin(), cache.end(), city);
        // 2) cache miss
        if(itr == cache.end()) {
            answer += 5;
            // 2-1) cache에 더 넣을 수 있는 경우
            if(cache.size() < cacheSize)
                cache.push_back(city);
            // 2-2) 이미 꽉 찬 경우
            else {
                cache.erase(cache.begin());
                cache.push_back(city);
            }
        }
        // 3) cache hit
        else {
            answer += 1;
            cache.erase(itr);
            cache.push_back(city);
        }
    }
    return answer;
}