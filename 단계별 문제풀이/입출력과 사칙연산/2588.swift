
/*
 < 2588: 곱셈 >  작성: YeonIsFree
 */

import Foundation

let num1: Int = Int(readLine()!)!
let num2: String = readLine()!
// [세자리 수를 각 자리수로 분해하는게 복잡할 것 같아서 정수형 배열로 바꿔버렸다]
let num2Arr: [Int] = num2.map{String($0)}.map{Int($0)!}

for i in stride(from: 2, through: 0, by: -1){
    print(num1 * num2Arr[i])
}
// [최종 결과]
print(num1 * Int(num2)!)
