
/*
 < 1932: 정수 삼각형 >  작성: YeonIsFree
 for문 돌릴때 범위를 1...size - 1로 하니 입력값이 1이 들어왔을 때 런타임 에러가 계속 떴다.
 다음번엔 조심해야할 듯!
 */

import Foundation

let size = Int(readLine()!)!
var arr = Array(repeating: [Int](), count: size)

for i in 0...size - 1 {
    arr[i] = readLine()!.split(separator: " ").map{Int($0)!}
}
if size == 1 {
    print(arr[0][0])
}else {
    for i in 1...size - 1 {
        for j in 0...i {
            if j == 0 {
                arr[i][j] += arr[i - 1][j]
            }else if i == j {
                arr[i][j] += arr[i - 1][j - 1]
            }else {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1])
            }
        }
    }
    print(arr[size - 1].max()!)
}

