
/*
 < 11054. 가장 긴 바이토닉 부분 수열  >  작성: YeonIsFree
LIS 문제의 응용 버전으로, 증가하는 수열과 감소하는 수열을 모두 찾아야하는 문제이다.
감소하는 수열을 찾을 때 좀 고생했는데, stride로 뒤부터 순회하는 방법도 좋지만,
아예 주어진 수열을 뒤집어 "증가"하는 수열을 찾은 뒤, 다시 뒤집어 주면 "감소"하는 수열이 되는 아이디어에 착안하였다.
 
참고 : https://velog.io/@sun02/Swift-백준-11054-가장-긴-바이토닉-부분-수열
*/

import Foundation

let num = Int(readLine()!)!
let numArr = readLine()!.split(separator: " ").map{Int($0)!}

var dpIncrease = Array(repeating: 1, count: num)
var dpDecrease = Array(repeating: 1, count: num)
var dpSum = Array(repeating: 0, count: num)

for i in 0..<num {
    for j in 0..<i {
        if numArr[j] < numArr[i] {
            dpIncrease[i] = max(dpIncrease[i], dpIncrease[j] + 1)
        }
    }
}

let reversed = Array(numArr.reversed())

for i in 0..<num {
    for j in 0..<i {
        if reversed[j] < reversed[i] {
            dpDecrease[i] = max(dpDecrease[i], dpDecrease[j] + 1)
        }
    }
}

dpDecrease = Array(dpDecrease.reversed())

for i in 0..<num {
    dpSum[i] = dpIncrease[i] + dpDecrease[i]
}

let maxValue = dpSum.max()!
print(maxValue - 1)
