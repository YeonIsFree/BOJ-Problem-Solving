
/*
 < 11053. 가장 긴 증가하는 부분 수열  >  작성: YeonIsFree
 가장 긴 증가하는 부분 수열(LIS)은 대표적인 Dynamic Programming 문제이다.
 처음에는 점화식이 왜 dp[i] = max(dp[i], dp[j] + 1) 인지 이해가 안가서 고생했다.
 기본 원리는 현재 값보다 작은 이전 순서의 값에 +1을 더하여 현재 값에 저장하고 그 다음 작은 값에 반복하여 시행한다.
 
 아래는 dp[3]을 구하는 예시이다.
 dp = [1, 2, 1, ?]이고 ? 가 현재 구해야할 dp[3]이며 그 값은 초기값 1로 세팅해둔 상태이다. --> dp[3] = 1
 i=3 ; j= 0 일때, dp[3] = max(dp[0] + 1, dp[3]) --> dp[0] + 1 즉 2가 채택됨. --> dp[3] = 2
       j= 1 일때, dp[3] = max(dp[1] + 1, dp[3]) --> dp[3]은 지금 2이고 dp[1] + 1 = 3이므로 3이 채택된다. --> dp[1] = 3
       j= 2 일때, dp[3] = max(dp[2] + 1, dp[3]) --> 2, 3이므로 3이 채택된다. --> dp[3] = 3
 
 참고 : https://blog.naver.com/tlsghdus3639/222837796761 의 설명이 큰 도움이 되었다.
 */

import Foundation

let arrLength = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int($0)!}
var dp = Array(repeating: 1, count: arrLength)

for i in 0..<arrLength {
    for j in 0..<i {
        if arr[j] < arr[i] {
            dp[i] = max(dp[i], dp[j] + 1)
        }
    }
}

print(dp.max()!)
