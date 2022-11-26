
/*
 < 1912. 연속합 >  작성: YeonIsFree
 
*/

import Foundation

let num = Int(readLine()!)!
let numArr: [Int] = readLine()!.split(separator: " ").map{Int($0)!}

var dp = Array(repeating: 0, count: num)

if num == 1 {
    print(numArr[0])
}else {
    dp[0] = numArr[0]
    for i in 1...num - 1 {
        dp[i] = max(dp[i - 1] + numArr[i], numArr[i])
    }
    print(dp.max()!)
}
