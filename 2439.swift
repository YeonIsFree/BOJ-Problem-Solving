import Foundation

/*
    < 2430: 별 찍기 - 2 >  작성: YeonIsFree
    stride 함수: by에서 지정한 값으로 건너뛴다
    stride(from: , to/through:   , by:   )  --> to는 미만, through는 이하
 */

let num: Int = Int(readLine()!)!

for i in 1...num {
    // [stride 함수의 by를 -1로 지정해주어 범위를 하나씩 감소]
    for _ in stride(from: num-i, to: 0, by: -1) {
        print(" ", terminator: "")
    }
    // [별 찍기]
    for _ in 1...i {
        print("*", terminator: "")
    }
    // [한 줄 완료하고 다음 줄로 개행]
    print("")
}
