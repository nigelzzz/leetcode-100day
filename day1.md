# leetcode 3393

## problem description
## example
## 解析
- 定義 dp[i][j][x] 為 走到 i, j 的並且xor value 為 x 方法數
思考路線: [0][0] 走到 [0][1] 的 value ==   [0][1] ^ [0][0] = k, k ^ [0][1] = [0][0]. 所以假設 最後
結果 ＝＝ k. 則 == 1.
- 轉移: 只能 右/下, 遞推 只能從 左/上
  - 來自左邊`i, j - 1` 的某條路徑, 其到 `i, j - 1`的 xor 必須是 `x ^ grid[i][j]`
  - `i - 1,j` 也是一樣
  - 所以 dp[i][j][x] = dp [i][j - 1][x^a[i][j]]  + dp[i - 1][j][x ^ a[i][j]]
  - base: dp[0][0][x] =1
```c++
int dfs(int i, int j, int res)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int gv = grid[i][j];
    if (i == 0 && j == 0)
        return res == gv; // 到 base case, 確認 xor 結果 == g[0][0]
    return dfs(i - 1, j, gv ^ res) + dfs(i, j - 1, gv ^ res);
}
int sol(vector<vector<int>> grid, int k)
{
    int x = grid.size();
    int y = grid[0].size();

    return dfs(x - , y - 1, k);
}
```
## 困難點
- 如果 xor value 大於 最大max 的 bit len, 則不可能找到答案. 
- memo[i][j][u], u 是 累積的xor 結果 所以數量 定義成u.
/// 找最大值，確定 XOR 狀態的範圍
int mx = 0;
for (auto &row : grid) {
    for (int v : row) mx = max(mx, v);
}
u = 1 << bit_width((unsigned)mx);
if (k >= u) return 0;                      // k 超過範圍，無解

memo.assign(m, vector<vector<int>>(n, vector<int>(u, -1)));  

## solved point




# leetcode 931
## problem description
- 2d array, 從最上面 row 往下走, 只能左下, 正下, 右下. 找最小路徑總和
## example

## 解析
- dp[i][j] 到達 i, j 的最小總和
- dp[i][j] = min(dp[i-1][j - 1], dp[i-1][j], dp[i-1][j + 1]);
- base case: first row dp[0][i] = g[0][i]
- ans: min(dp[r].begin(), dp[r].end());
```c++
int minFallingPathSum(vector<vector<int>>& matrix) {
        int x = matrix.size();
        int y = matrix[0].size();
        vector<vector<int>> dp(x, vector<int>(y));
        for (int i = 0; i< x; i++)
            dp[0][i] = matrix[0][i];
        for (int i = 1; i< x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                // 比三次
                int best = dp[i - 1][j];
                if (j > 0)
                    best = min(best, dp[i - 1][j - 1]);
                if (j < x-1)
                    best = min(best, dp[i - 1][j +1]);
                // 當下 剛左上 右上 正上
                dp[i][j]  = matrix[i][j] + best;
            }
        }
        return *min_element(dp[y - 1].begin(), dp[y - 1].end());
    }
```
## 困難點
- [ ] 邊界 e.g., 超過 x or y,
- [ ] 
## solved point
