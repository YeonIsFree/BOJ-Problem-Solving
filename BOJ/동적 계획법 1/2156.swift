
/*
 < 2156. 포도주 시식  >  작성: YeonIsFree
계단 문제와 유사한 문제로 연속으로 세 잔을 마실 수 없다는 제약 조건에 유의한다.
추가된 개념은 현재 순서의 와인을 반드시 마시지 않아도 되므로 경우의 수가 하나 더 늘어난다.
*/

import Foundation

let num = Int(readLine()!)!
var wines = Array(repeating: 0, count: num + 1)

for i in 1...num {
    wines[i] = Int(readLine()!)!
}

var dp = Array(repeating: 0, count: num + 1)

for i in 1..<num + 1 {
    if i == 1 {
        dp[1] = wines[1]
    } else if i == 2 {
        dp[2] = wines[1] + wines[2]
    } else {
        dp[i] = max(dp[i-2] + wines[i], dp[i-3] + wines[i-1] + wines[i], dp[i-1])
    }
}
print(dp.max()!)

