
/*
 < 1143. Longest Common Subsequence  >  작성: YeonIsFree

 */

import Foundation

class Solution {
    func longestCommonSubsequence(_ text1: String, _ text2: String) -> Int {
        var dp = Array(repeating: Array(repeating: 0, count: text2.count + 1), count: text1.count + 1)

        let text1 = Array(text1)
        let text2 = Array(text2)

        for i in 1...text1.count {
            for j in 1...text2.count {
                if text1[i-1] == text2[j-1] {
                    dp[i][j] = dp[i-1][j-1] + 1
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                }
            }
        }

        return dp[text1.count][text2.count]
    }
}
