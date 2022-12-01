
/*
 < 9251. LCS  >  작성: YeonIsFree
 LCS는 Longest Common Sequeces의 약자로 대표적인 DP문제이다.
 예전에 풀었던 최대 부분 배열 길이 (Longest Common "Substring") 문제와는 다르게 "Sequece"는 문자열이 연속되지 않아도 된다.
 */

import Foundation

let m = Array(readLine()!)
let n = Array(readLine()!)
var dp = Array(repeating: Array(repeating: 0, count: n.count + 1), count: m.count + 1)

for i in 1...m.count {
    for j in 1...n.count {
        if m[i-1] == n[j-1] {
            dp[i][j] = dp[i-1][j-1] + 1
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        }
    }
}

print(dp[m.count][n.count])

