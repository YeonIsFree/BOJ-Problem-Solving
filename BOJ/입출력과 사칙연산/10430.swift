import Foundation

/*
    < 10430: 나머지 >  작성: YeonIsFree
 */

let nums = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}

let A = nums[0]
let B = nums[1]
let C = nums[2]

print("\( (A+B)%C )")
print("\( ((A%C) + (B%C))%C )")
print("\( (A*B)%C )")
print("\(  ((A%C) * (B%C))%C )")
