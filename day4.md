2466. 统计构造好字符串的方案数
## problem description

- 给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
    - 将 '0' 在字符串末尾添加 zero  次。
    - 将 '1' 在字符串末尾添加 one 次。
- 以上操作可以执行任意次。
如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 109 + 7 取余 后返回。

- 示例 1：

输入：low = 3, high = 3, zero = 1, one = 1
输出：8
解释：
一个可能的好字符串是 "011" 。
可以这样构造得到："" -> "0" -> "01" -> "011" 。
从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。

- 示例 2：

输入：low = 2, high = 3, zero = 1, one = 2
输出：5
解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。

## example
## 解析
- 根據題目每次只能往後加入 0, 1 , 單次加入的次數 取決於 zero 跟 one 的 value. 
- dfs.
```c++ 
for (low to high)
    res = dfs(i + zero) + dfs(i + one)
return res?

static constexpr int MOD = 1'000'000'007;
    int low_, high_, zero_, one_;
    vector<int> memo;

    int dfs(int len) {
        if (len > high_) return 0;
        int &res = memo[len];
        if (res != -1) return res;

        long long ans = (len >= low_) ? 1 : 0;  // 當前長度本身是否已達成一個好字串
        ans += dfs(len + zero_);
        ans += dfs(len + one_);
        return res = (int)(ans % MOD);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        low_ = low; high_ = high; zero_ = zero; one_ = one;
        memo.assign(high + 1, -1);
        return dfs(0);
    }
```
靈神的解
- dfs(i) 定義成 解為 i 的方案數
- 當最後的 value 為 zero, 則剩下則是 target - zero.

如果 target - zero == 0, 則有解..., 
```cpp
 int countGoodStrings(int low, int high, int zero, int one) {

        const int MOD = 1'000'000'007;

        vector<int> memo(high + 1, -1); // -1 表示没有计算过

        auto dfs = [&](auto&& dfs, int i) -> int {

            if (i < 0) {

                return 0;

            }

            if (i == 0) {

                return 1;

            }

            int& res = memo[i]; // 注意这里是引用

            if (res != -1) { // 之前计算过

                return res;

            }

            return res = (dfs(dfs, i - zero) + dfs(dfs, i - one)) % MOD;

        };

        int ans = 0;

        for (int i = low; i <= high; i++) {

            ans = (ans + dfs(dfs, i)) % MOD;

        }

        return ans;

```
## 困難點

top down 比較需要思考？　
- 當定義 dfs(i) == 解 為 i 的方案數
-  
- dfs(1) + dfs(2) = dfs(3).......
## solved point