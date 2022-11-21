
/*
    < 2480: 주사위 세개 >  작성: YeonIsFree
 */

import Foundation

let input = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}

if input[0] == input[1] && input[1] == input[2] {
    print(10000 + input[0] * 1000)
} else if input[0] == input[1] || input[1] == input[2]{
    print(1000 + input[1] * 100)
}
else if input[0] == input[2]{
    print(1000 + input[0] * 100)
}
else{
    print(input.max()! * 100)
}
