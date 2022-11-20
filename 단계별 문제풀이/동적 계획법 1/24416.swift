
/*
 < 24416: 알고리즘 수업 - 피보나치 수 1 >  작성: YeonIsFree
 */

import Foundation

let n = Int(readLine()!)!

func recurFib(_ n: Int) -> Int {
    var count = 0
    if n == 1 || n == 2 {
        count += 1
        return 1
    }
    return recurFib(n - 1) + recurFib(n - 2)
}

func dpFib(_ n: Int) -> Int {
    var count = 0
    var f = Array(repeating: 0, count: n + 10)

    f[1] = 1
    f[2] = 1
    
    for i in 3...n {
        count += 1
        f[i] = f[i - 1] + f[i - 2]
    }
  
    return count
}

print(recurFib(n), dpFib(n))
