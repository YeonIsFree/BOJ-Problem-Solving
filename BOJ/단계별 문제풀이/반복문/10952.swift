import Foundation

/*
    < 10952: A+B - 5 >  작성: YeonIsFree
    
 */

// [우선 While문으로 무조건 진입]
while true {
    let input: [Int] = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
// [ 입력값으로 "0 0"이 들어오면 break로 While 루프를 탈출한다 ]
    if input[0] == 0 && input[1] == 0 {
        break
    }
    print(input[0]+input[1])
}

