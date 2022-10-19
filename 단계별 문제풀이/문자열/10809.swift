
/*
 < 10809: 알파벳 찾기 >  작성: YeonIsFree
 좋은 코드는 아닌 것 같다... 다른 풀이도 좀 찾아봐야겠다.
 */

import Foundation

// [입력값 각각의 알파벳을 아스키값으로 바꿔주고, "a"의 아스키값을 뻬준다 -> 알파벳 위치 인덱스로 활용 가능]
let words = readLine()!.map{ $0.asciiValue! }.map{ Int(exactly: $0 - Character("a").asciiValue!)! }
// [ a~z 26개의 -1로 채워진 배열 생성 ]
var checkArr = Array(repeating: -1, count: 26)
// [ checkArr[words의 값자체] = words의 index ]
for i in words {
    checkArr[Int(i)] = words.firstIndex(of: i)!
}

checkArr.forEach {
    print($0, terminator: " ")
}
