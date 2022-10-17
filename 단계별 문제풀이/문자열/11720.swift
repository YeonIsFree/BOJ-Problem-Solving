
/*
 < 11720: 숫자의 합 >  작성: YeonIsFree
 swift의 reduce 함수 덕에 num 변수는 쓰지 않아도 괜찮다.
 입력 형식을 맞추기 위해 작성만 해둠.
 */

import Foundation
let num = readLine()!
let sum = readLine()!.map{Int(String($0))!}.reduce(0){ $0 + $1 }
print(sum)
