
/*
 < 1920. 수 찾기 >  작성: YeonIsFree

*/

import Foundation

let input1 = Int(readLine()!)!
let input1Arr = readLine()!.split(separator: " ").map{Int($0)!}.sorted()

let input2 = Int(readLine()!)!
let input2Arr = readLine()!.split(separator: " ").map{Int($0)!}
func search(nums: [Int], target: Int) {
    var left = 0
    var right = input1 - 1
    
    while left <= right {
        let pivot = (left + right) / 2
        if nums[pivot] == target {
            return print("1")
        } else if nums[pivot] < target {
            left = pivot + 1
        } else { //nums[pivot] > target
            right = pivot  - 1
        }
    }
    
    return print("0")
}

for num in input2Arr {
    search(nums: input1Arr, target: num)
}
