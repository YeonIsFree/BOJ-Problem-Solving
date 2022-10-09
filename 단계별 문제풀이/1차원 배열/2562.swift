import Foundation

/*
    < 2562: 최댓값 >  작성: YeonIsFree
 */

var arr: [Int] = []
var maxNum = 0

for i in 0...8{
    arr.append(Int(readLine()!)!)
    if arr[i] > maxNum {
        maxNum = arr[i]
    }
}

print(maxNum)
print(arr.firstIndex(of: maxNum)! + 1)
