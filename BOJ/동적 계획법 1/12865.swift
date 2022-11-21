
/*
 < 12865: 평범한 배낭 >  작성: YeonIsFree
 */

import Foundation

let input = readLine()!.split(separator: " ").map{Int($0)!}
let N = input[0]
let K = input[1]
var W = Array(repeating: 0, count: 1010)
var V = Array(repeating: 0, count: 1010)
var dp = Array(repeating: Array(repeating: 0, count: 100010), count: 1010)

for i in 1...N {
    let jewel = readLine()!.split(separator: " ").map{Int($0)!}
    W[i] = jewel[0]
    V[i] = jewel[1]
}

for i in 1...N {
    for j in 1...K {
        if W[i] > j {
            dp[i][j] = dp[i-1][j]
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j - W[i]] + V[i])
        }
    }
}

print(dp[N][K])
