# Google Interview Sliding Window & Two Pointers Curriculum

主要來源：靈茶山艾府〈滑動窗口與雙指針〉

來源：https://leetcode.cn/discuss/post/3578981/ti-dan-hua-dong-chuang-kou-ding-chang-bu-rzz7/

原則：不按完整題單逐題刷完；先掌握核心模板，再完成約 30 題代表題。完成狀態以 `profile.yaml`、`mistakes.yaml` 與 `sessions/` 為準。

## Week 1：定長滑動窗口

順序：

1. 1456 — Maximum Number of Vowels in a Substring of Given Length
2. 643 — Maximum Average Subarray I
3. 1343 — Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
4. 2090 — K Radius Subarray Averages
5. 2379 — Minimum Recolors to Get K Consecutive Black Blocks
6. 2461 — Maximum Sum of Distinct Subarrays With Length K

目標：看到「長度固定為 k」，能立即定義第一個窗口、outgoing index 與 incoming index。

```cpp
long long sum = 0;
for (int i = 0; i < k; i++) {
    sum += nums[i];
}

long long ans = sum;
for (int right = k; right < nums.size(); right++) {
    sum -= nums[right - k];
    sum += nums[right];
    ans = max(ans, sum);
}
```

核心 invariant：處理完 `right` 後，目前窗口是 `[right-k+1, right]`。

## Week 2：不定長窗口，求最長

順序：

1. 3 — Longest Substring Without Repeating Characters
2. 3090 — Maximum Length Substring With Two Occurrences
3. 904 — Fruit Into Baskets
4. 1004 — Max Consecutive Ones III
5. 2024 — Maximize the Confusion of an Exam
6. 2958 — Length of Longest Subarray With at Most K Frequency

目標：能定義「窗口何時不合法」。右指針擴張；不合法時移動左指針，恢復合法後更新最大長度。

## Week 3：不定長窗口，求最短與計數

順序：

1. 209 — Minimum Size Subarray Sum
2. 713 — Subarray Product Less Than K
3. 1358 — Number of Substrings Containing All Three Characters
4. 2962 — Count Subarrays Where Max Element Appears at Least K Times
5. 930 — Binary Subarrays With Sum
6. 1248 — Count Number of Nice Subarrays

延伸代表題：1234、76、992。

目標：分清三種更新方式：

```cpp
ans = max(ans, right - left + 1);
ans = min(ans, right - left + 1);
ans += right - left + 1;
```

恰好型轉換：

```text
exactly(k) = atMost(k) - atMost(k-1)
```

## Week 4：相向雙指針

順序：

1. 125 — Valid Palindrome
2. 977 — Squares of a Sorted Array
3. 167 — Two Sum II
4. 11 — Container With Most Water
5. 15 — 3Sum
6. 42 — Trapping Rain Water

目標：每次移動指針時，都能說明為什麼不會錯過答案。

## 必須避免的錯誤

1. 整數除法：需要平均值時先轉成 `double`；能交叉相乘時優先比較整數。
2. `sum` 在窗口生命週期內必須保存總和，不可在建立窗口時反覆除法。
3. 先確認窗口長度是否可能大於陣列長度；例如 2090 的窗口大小是 `2*k+1`。
4. 定長窗口的 outgoing index 是 `right-k`，不是 `right-k-1`。
5. 合法窗口數量是 `n-k+1`。
6. 兩個 sequential loops 的總工作量可能是 `k+(n-k)=n`；不可只因有兩個 loops 就判定 `O(n²)`。

## 目前進度

- 1456：完成
- 643：完成
- 1343：完成
- 2090：使用者回報先前已完成，本輪尚未重新評估
- 2379：完成
- 2461：完成
- Week 1 定長滑動窗口：完成
- 下一題：3 — Longest Substring Without Repeating Characters
