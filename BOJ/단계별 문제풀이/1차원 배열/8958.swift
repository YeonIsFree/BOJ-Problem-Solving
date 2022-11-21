
/*
 < 8958: OX퀴즈 >  작성: YeonIsFree
 "OOX" 로 들어오는 입력을 ["O", "O", "X"]로 변환하는 방법을 몰라 오래걸렸는데,
 String 자체를 배열처럼 .map( String($0) )로 한글자 한글자 매핑해주면 되었다.
 (String을 배열로 취급하는걸까? 확실하지 않음)
 */

import Foundation

let caseNum = Int(readLine()!)!
// [입력 받은 케이스 숫자만큼 반복]
for _ in 1...caseNum {
    // [각 테스트 케이스 입력]
    let caseArr = readLine()!.map{ String($0) }
    
    while true {
        var count = 0
        var sum = 0
        
        for i in caseArr{
            if i == "O" {
                // [count로 연속으로 나오는 "O"의 갯수를 기록해준다]
                count += 1
                sum += count
            } else {
                // ["X"를 만났을 경우 count를 0으로 초기화하고 다음 사이클로 진행]
                count = 0
                continue
            }
        }
        // [테스트 케이스 검사가 끝났으니 값을 출력]
        print(sum)
        // [다음 테스트를 위해 sum과 count를 초기화 해주고 while문을 탈출]
        sum = 0
        count = 0
        
        break
    }
    
}



