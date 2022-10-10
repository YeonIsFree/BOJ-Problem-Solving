
/*
    < 2525: 오븐 시계 >  작성: YeonIsFree
 */

import Foundation

let input1 = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
let input2 = readLine()!

let endTime = (input1[0]*60 + input1[1]) + Int(input2)!
var endHour = endTime / 60
let endMin = endTime % 60

if endHour >= 24 {
    endHour -= 24
}

print(endHour, endMin)
