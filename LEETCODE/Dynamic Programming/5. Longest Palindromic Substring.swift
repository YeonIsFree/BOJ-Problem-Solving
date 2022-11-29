
/*
 < 5. Longest Palindromic Substring >  작성: YeonIsFree
출처 : 유튜브 '코드 없는 프로그래밍' 채널의 파이썬 코드를 참조
 */

import Foundation

func longestPalindrome(_ s: String) -> String {
    let strArray = Array(s)
    let strLength = strArray.count
    // [ 문자열 길이를 n이라 하자. 먼저, n x n 2원 배열을 생성한다. ]
    var dp = Array(repeating: Array(repeating: 0, count: strLength), count: strLength)
    // [길이가 1짜리인 문자열이 들어오면 그대로 출력하고 일찌감치 종료시킨다]
    if strLength == 1 {
        return s
    }
    // [ dp 배열의 중앙 대각선( (0,0), (1,1), (2,2) ... )을 채운다. 이때 이 대각선은 문자열 중 글자수 하나일 때를 의미하므로 팰린드롬 길이가 무조건 1이 된다. ]
    for i in 0..<strLength {
        dp[i][i] = 1
    }
    // [ 위에서 채운 중앙 대각선의 다음 대각선을 채운다. ]
    for i in 0..<strLength - 1 {
        if strArray[i] == strArray[i + 1] {
            dp[i][i + 1] = 2
        }
    }
    // [ 그 다음은 다이나믹 프로그래밍을 적용한다. 왼쪽 대각선 아래(prev)의 값이 0이 아니고 현재 인덱스의 앞뒤 값이 같은지 비교 하고 +2를 더해준다.  ]
    for i in 2..<strLength {
        var row = 0
        var col = i
        
        while col < strLength {
            let prev = dp[row + 1][col - 1]
            if strArray[row] == strArray[col] && prev != 0 {
                dp[row][col] = prev + 2
            }
            row += 1
            col += 1
        }
    }
    
    var max = 0
    var startIdx = 0
    var endIdx = 0
    // [ 2차원 배열의 max 값 찾기. 최대값의 인덱스를 저장해야하기 때문에 이중 for문을 돌려준다. ]
    for i in 0..<strLength {
        for j in 0..<strLength {
            if max < dp[i][j] {
                max = dp[i][j]
                startIdx = i
                endIdx = j
            }
        }
    }
    
    let maxSubArr = String(strArray[startIdx...endIdx])
    
    return maxSubArr

}
