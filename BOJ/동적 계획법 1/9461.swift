
/*
 < 9461. 파도반 수열 >  작성: YeonIsFree
 문제의 점화식을 찾기는 쉬웠으나 파도반 수열 자체가 무슨 뜻인지 이해가 가질 않아서 애먹었다.
 결국 다음 정삼각형을 변을 만들 때 바로 직전(i - 1) + 다섯번째 전(i - 5) 정삼각형의 변을 이용한다는 점에 착안하여
 점화식을 만들면 간단히 풀 수 있는 문제였다.
 */


import Foundation

let num = Int(readLine()!)!
var dp = Array(repeating: 0, count: 101)

dp[1...5] = [1, 1, 1, 2, 2]

for i in 6..<101 {
    dp[i] = dp[i - 5] + dp[i - 1]
}

for _ in 1...num {
    let n = Int(readLine()!)!
    print(dp[n])
}
