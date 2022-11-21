
/*
 < 2839: 설탕 배달 >  작성: YeonIsFree
 다이나믹 프로그래밍으로 풀어봄.
 */

import Foundation

let inputNum = Int(readLine()!)!
var result = 0
var dp = [0, 5000, 5000, 1, 5000, 1]

if inputNum <= 5 {
    result = dp[inputNum]
}else {
    for i in 6...inputNum {
        dp.append(min(dp[i-5] + 1, dp[i-3] + 1))
    }
    result = dp[inputNum]
}

if result >= 5000 {
    print(-1)
} else {
    print(result)
}
