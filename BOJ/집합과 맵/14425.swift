
/*
 < 14425. 문자열 집합 >  작성: YeonIsFree
 배열로 풀었더니 시간 초과가 났다. Set으로도 풀 수 있지만 Dictionary에 넣고 해당 key의 value로 문자열이 들어있는지 체크했다.
 참고 : https://blog.naver.com/gustn3964/222176891598
*/

import Foundation

let n = readLine()!.split(separator: " ").map{Int($0)!}
var inputDict = [String:Int]()

for _ in 1...n[0] {
    inputDict[readLine()!] = 1
}

var count = 0

for _ in 1...n[1] {
    let strInput = readLine()!
    count += inputDict[strInput] != nil ? 1 : 0
}

print(count)
