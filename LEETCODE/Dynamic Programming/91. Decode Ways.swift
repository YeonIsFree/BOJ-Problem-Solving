
/*
 < 91. Decode Ways >  작성: YeonIsFree
*/

import Foundation

class Solution {
    func numDecodings(_ s: String) -> Int {
        
        let sArray = Array(s)
        let strLength = sArray.count
        if strLength == 1 { return sArray[0] == "0" ? 0 : 1}
        
        var dp = Array(repeating: 0, count: strLength + 1)
        dp[0] = 1
        dp[1] = (sArray[0] == "0" ? 0 : 1)
        
        for i in 2...strLength {
            if sArray[i - 1] != "0" {
                dp[i] += dp[i - 1]
            }
            
            let twoDigit = Int(String(sArray[i-2...i-1]))!
            if 10 <= twoDigit && twoDigit <= 26 {
                dp[i] += dp[i - 2]
            }
            
        }
        
        return dp[strLength]
    }
}
