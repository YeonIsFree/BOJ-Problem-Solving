
/*
 < 1065: 한수 >  작성: YeonIsFree
 1) 어떤 수를 입력받는다.
 2) 그 수를 한수카운터 함수에 넣는다. 한수카운터는 아래와 같이 작동한다.
   2-1) 그 수가 99 이하인 경우: 그 수 자체를 카운트에 입력
   2-2) 그 수가 100 이상인 경우: 100부터 그 수까지 한수를 세준다.
        (중요: 이때 1 ~ 99는 이미 한수이므로 카운트에 99를 넣고 시작한다.)
 3) 최종 카운트 출력
 */

import Foundation

let inputNum = Int(readLine()!)!

func hansuCounter(_ num: Int) -> Int {
    var count = 0
    if num < 100 {
        count = num
    } else {
        count = 99
        for i in 100...num {
            let numArr: [Int] = String(i).map{Int(String($0))!}
            if numArr[0] - numArr[1] == numArr[1] - numArr[2] {
                count += 1
            } else { continue }
        }
    }
    return count
}

print(hansuCounter(inputNum))
