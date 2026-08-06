# 70. 爬楼梯 (Climbing Stairs)
- problem description

一次可以爬 1 或 2 階，爬到第 n 階有幾種方法。

example

n=3：(1+1+1), (1+2), (2+1) → 3

- 解析

狀態：dp[i] = 到第 i 階的方法數

轉移：dp[i] = dp[i-1] + dp[i-2]

初值：dp[0]=1（在地面不動一種方式）、dp[1]=1

- 困難點

dp[0] 設為 1 的語義：用於「組合數學上的空方式」。

- solved point

其實是 Fibonacci；可用 O(1) 空間滾動。

# 746. 使用最小花费爬楼梯 (Min Cost Climbing Stairs) zzz 746 想不起來 要在練習
- problem description

cost[i] 為踩在第 i 階需花費；可從 i 走 i+1 或 i+2，起點可在 0 或 1，終點是「樓頂」(n)。

example

cost=[10,15,20] → 最小成本 15（走 1→3）

- 解析

狀態：dp[i] = 抵達第 i 階的最小成本

初值：dp[0]=cost[0], dp[1]=cost[1]

轉移：dp[i] = min(dp[i-1], dp[i-2]) + cost[i]

答案：min(dp[n-1], dp[n-2])（最後一步可跨到頂）

- 困難點

樓頂不花錢（不加 cost）；要取末兩階的最小值。

- solved point

O(1) 空間兩變數滾動。

# 377. 组合总和 IV (Combination Sum IV) 想不起來 要在練習
- problem description

給 nums（正整數可重用）與目標 target，順序不同算不同方式；求和為 target 的組合數。

example

nums=[1,2,3], target=4
序列：(1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1) → 7

- 解析

狀態：dp[t] = 和為 t 的序列數

初值：dp[0]=1

轉移（序列、順序敏感 → 外層 target）：
for t=1..T: for x in nums: if t>=x: dp[t]+=dp[t-x]

  - dfs
```
vector<int> arr;
int dfs(int target)
{
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    int res = 0;
    for (auto n: arr)
    {
        if (target >= n)
            res += dfs(target - n);
    }
    return res;
}
// 找到 nums 裡面總和 為 target 的方法數
int func(vector<int> nums, int target)
{
    arr = nums;
    return dfs(target);
}
```
- 困難點

與「完全背包（組合、順序不敏感）」不同，外層必須是 t 才能讓順序生效。

大值需 long long 或取模（題目若要求）。

- solved point

明確記住：這題是「排列數」，不是組合數。