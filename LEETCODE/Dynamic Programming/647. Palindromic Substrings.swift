
/*
 < 647. Palindromic Substrings >  작성: YeonIsFree
 */


import Foundation

func countSubstrings(_ s: String) -> Int {
        let strArray = Array(s)
        let strLength = strArray.count
        var dp = Array(repeating: Array(repeating: false, count: strLength), count: strLength)
        var count = 0

        if strLength == 1 { return 1 }
        
        for i in 0..<strLength {
            dp[i][i] = true
            count += 1
        }
    
        for i in 0..<strLength - 1 {
            if strArray[i] == strArray[i + 1]{
                dp[i][i + 1] = true
                count += 1
            }
        }

       for j in 2..<strLength {
           var row = 0
           var col = j

           while col < strLength {
               if strArray[row] == strArray[col] && dp[row + 1][col - 1] {
                   dp[row][col] = true
                   count += 1
               }
               row += 1
               col += 1
           }
       }
    
        return count
}
