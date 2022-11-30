
/*
 < 2941. 크로아티아 알파벳 >  작성: YeonIsFree
 replacingOccurrences을 이용한 문자열 치환을 공부할 수 있는 문제였다.
 입력받은 문자열에서 arr에 들어있는 크로아티아 문자열을 만나면 "c" 라는 하나의 단어로 바꾸어준다.
 "c=" "c-" 등과 같이 2개의 글자로 이루어져있는 문자를 "하나의" 문자로 인식시키는 원리이다.
 */


import Foundation

let arr = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

var inputStr = readLine()!

for i in arr {
    inputStr = inputStr.replacingOccurrences(of: i, with: "c")
}

var count = inputStr.count

print(count)
