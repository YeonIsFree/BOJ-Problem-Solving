
/*
 < 64. Minimum Path Sum >  작성: YeonIsFree
*/

class Solution {
    func minPathSum(_ grid: [[Int]]) -> Int {
        let rows = grid.count
        let cols = grid[0].count
        // [문제에서 정의된 grid 이차원 배열이 let으로 선언되어 있어서 dp 라는 새로운 테이블을 만들어서 진행]
        var dp = grid
        // [가로 테두리 쪽, 세로 테두리 쪽 채우기]
        for i in 1..<rows {
            dp[i][0] += dp[i - 1][0]
        }
        for j in 1..<cols {
            dp[0][j] += dp[0][j - 1]
        }
        // [안쪽 채우기]
        for i in 1..<rows {
            for j in 1..<cols {
                let upDp = (j - 1 < 0 ? 0 : dp[i - 1][j])
                let leftDp = (i - 1 < 0 ? 0 : dp[i][j - 1])

                dp[i][j] += min(upDp, leftDp)
            }
        }

        return dp[rows-1][cols-1]
    }
}
