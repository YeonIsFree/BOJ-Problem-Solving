
/*
    < 2884: 알람 시계 >  작성: YeonIsFree
 */

import Foundation

let input = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
// [시간을 분으로 바꿔 계산한다. 예: 2시간 15분 = 120분 + 15분 = 135분]
let hour = input[0] * 60
let min = input[1]

var convertedTime = (hour + min) - 45

// [00시 15분과 같이 자정 무렵 시간이 입력되면 결과값이 음수가 나올 수 있으므로, 이를 방지하기 위한 식]
if convertedTime < 0 {
    convertedTime += 24*60
    
}

print(convertedTime/60, convertedTime%60)

