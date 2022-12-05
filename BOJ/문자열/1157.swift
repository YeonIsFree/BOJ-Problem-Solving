
/*
 < 1157. 단어 공부  >  작성: YeonIsFree
Set으로 문자의 중복을 제거해주고 다시 Array 형태로 바꾸어준다. Set은 순서가 없기 때문에 인덱스 활용이 불가능하기 때문이다.
가장 많이 사용되는 알파벳이 여러 개 존재하는 경우는 해당 글자의 firstIndex 와 lastIndex가 다른 경우로 찾아줄 수 있다.
*/

import Foundation

let stringArr = Array(readLine()!.uppercased())
let charSet = Array(Set(stringArr))
var countArr = Array(repeating: 0, count: charSet.count)

for i in 0..<stringArr.count {
    for char in charSet {
        if char == stringArr[i] {
            let idx = charSet.firstIndex(of: char)!
            countArr[idx] += 1
        }
    }
}

let maxValue = countArr.max()!
if countArr.firstIndex(of: maxValue) != countArr.lastIndex(of: maxValue) {
    print("?")
} else {
    let maxIdx = countArr.firstIndex(of: maxValue)!
    print(charSet[maxIdx])
}

