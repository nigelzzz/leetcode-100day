# leetcod 2684
## problem description
- 給定 m * n 矩陣, 從 0 ~ m row 往右邊找路徑
- 只能 右上 左 右下, 並且找的點要比前一個大.
## example
grid =
[ [2, 4, 3, 5],
  [5, 4, 9, 3],
  [3, 4, 2,11] ]
ans = 3
- 例：2→4→9→11，共 3 步
## 解析
- 用 dfs, dfs(i, j) == 從 i j 出發的最多步. 

```c++
vector<vector<int>> g;
int x = 0;
int y = 0;
vector<vector<int>>memo;
    int dfs(int i , int j)
    {
        int best = 0;
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (j + 1　< y)
        {
            for (int d: {-1, 0, 1})
            {
                int ni = i + d;
                int nj = j + 1;
                if (ni <x && ni >= 0 && g[ni][nj] > g[i][j])
                {
                    best = max(best, dfs(ni, nj) + 1);
                }
            }
        }
        return memo[i][j] = best;
    };
    int maxMoves(vector<vector<int>>& grid) {
       int ans = 0;
         x = grid.size();
         y = grid[0].size();
        g = grid;
        memo.assign(x, vector<int>(y, -1));
        for (int i = 0; i < x; i++)
        {
            // 從 0 col 出發..每個 row 都 try一遍
            ans = max(ans, dfs(i,0));
        }
        return ans; 
    }
```
- dp 
```c++
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j] = 從 (i,j) 出發的最大步數

        for (int j = n - 2; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                int best = 0;
                for (int di : {-1, 0, 1}) {
                    int ni = i + di, nj = j + 1;
                    if (0 <= ni && ni < m && grid[ni][nj] > grid[i][j]) {
                        best = max(best, 1 + dp[ni][nj]);
                    }
                }
                dp[i][j] = best;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) ans = max(ans, dp[i][0]);
        return ans;
    }
};
```
## 困難點
- 為何要從右邊往左邊算? 每一步 依賴 j + 1 的點
- 
## solved point
- 邊界要設定好,j < n + 1, ni < x, ni >= 0..
- 用 memo 把每一輪算好的最大 value 存起來. 

# leetcode 3603

## problem description
網格大小 m×n。進入 (i,j) 成本為 (i+1)*(j+1)；另有 waitCost[i][j]。你從 (0,0) 第 1 秒開始：

奇數秒必須向右或下移動並支付進入成本；

偶數秒必須原地等待並支付 waitCost。
求到達 (m-1,n-1) 的最小總成本。
## example
m=2,n=2, waitCost=[[3,5],[2,7]]
可走：t1 移到 (0,1) 付 1×2=2；
t2 在 (0,1) 等待付 5；
t3 移到 (1,1) 付 2×2=4 → 總成本 11（到終點不再等待）。
## 解析
- 起點跟終點 不用等待（基數）　終點不用等待是因為 2t - 1, 一定是 几數
- dfs(i, j) 等於 走到 i j 的最小路徑合分數
```cpp
long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector memo(m, vector<long long>(n));
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (i < 0 || j < 0) {
                return LLONG_MAX;
            }
            if (i == 0 && j == 0) {
                return 1; // 起点只有进入成本，不需要等待
            }
            long long& res = memo[i][j]; // 注意这里是引用
            if (res != 0) { // 之前计算过
                return res;
            }
            long long cost = waitCost[i][j] + 1LL * (i + 1) * (j + 1);
            return res = min(dfs(i, j - 1), dfs(i - 1, j)) + cost;
        };
        return dfs(m - 1, n - 1) - waitCost[m - 1][n - 1]; // 终点不需要等待
    }

```
## 困難點
- 要想到 起點跟終點 不用等待.. 
- 基數跟偶數 是一起算所以不用特別判斷 當下秒數 是 odd or even...
## solved point


# 2304. 网格中的最小路径代价 1658
## problem description
(x + 1, 0), 
(x + 1, 1), ..., 
(x + 1, n - 1) 中的任何一个单元格
可以移動到下一個 row 的任一格


## example
grid = [[5,3],
        [4,0],
        [2,1]]

moveCost = [[9,8],
            [1,5],
            [10,12],
            [18,6],
            [2,4],
            [14,3]]

- grid 的值範圍是 0 ~ 5（因為出現了 5）。
所以 moveCost 有 6 行（0~5），每行長度等於 grid 的欄數 n=2。

舉例：
在 grid[0][0] = 5 的格子（值是 5），如果要往下一行第 0 欄走：
成本 = moveCost[5][0] = 14
如果要往下一行第 1 欄走：
成本 = moveCost[5][1] = 3
在 grid[1][1] = 0 的格子（值是 0），如果往下一行第 0 欄走：
成本 = moveCost[0][0] = 9
如果往下一行第 1 欄走：
成本 = moveCost[0][1] = 8
## 解析
- dp 有 `選跟不選`  or `枚舉選哪個` 
- dfs(i, j) 等於 走到 i j 的最小path sum
- min(res, dfs(i, j + 1) + moveCost[i][j]) 
- dfs(i, j) = grid[i][j] + min(dfs(i, j+ 1)) + movecost[grid[i][j]][j] ; 
```
 vector<vector<int>> g, mc;
    int x, y;
    vector<vector<int>> memo;
    const int INF = 1e9;

    int dfs(int i, int j) {
        if (i == x - 1) return g[i][j];           // 底行：只需要包含自己
        int &res = memo[i][j];
        if (res != -1) return res;

        int v = g[i][j];
        int best = INF;
        for (int k = 0; k < y; ++k) {             // 下一行的所有欄位
            best = min(best, mc[v][k] + dfs(i + 1, k));
        }
        return res = g[i][j] + best;               // 當前格子 + (移動成本 + 下方最優)
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        g = grid; mc = moveCost;
        x = g.size(); y = g[0].size();
        memo.assign(x, vector<int>(y, -1));

        int ans = INF;
        for (int j = 0; j < y; ++j) {              // 起點可在第0行任意欄
            ans = min(ans, dfs(0, j));
        }
        return ans;
    }
```



## 困難點
- 要想到 mc[ g[i][j]][k] + dfs(i + 1, k)  -> 求 每一行的最小消耗
- 最後在加上 g[i][j]
- 要有兩個 forlopp,
- 第一個是在第一個 row iterate every col. 
- 第二個是 遞迴要在每個 col 求最小消耗 
## solved point
