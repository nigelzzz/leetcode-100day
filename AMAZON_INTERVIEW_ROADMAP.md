# Amazon Interview Roadmap: 由淺入深題單

Last updated: 2026-08-31

定位：Amazon 的 coding 題比 Google 更「可預測」，高頻題集中在固定幾個 pattern；但 Amazon 多了兩個 Google 沒有的重點：OA 的 Work Simulation / Work Style（依 Leadership Principles 評分）、以及每一輪 coding 前後都會問 1-2 題 LP behavioral。所以準備方式是「pattern 題單 + LP 故事庫」並行，不是只刷題。

流程校正（2026）：

- OA（SDE I）：2 題 coding（70-90 分鐘）+ Work Simulation（約 50 分鐘）+ Work Style Assessment（15-20 分鐘）。很多人 coding 全過卻在 simulation 被刷。
- OA（SDE II）：90 分鐘 coding + 20 分鐘 System Design scenario + 8 分鐘 Work Style Survey。
- Phone screen：1 輪，coding + 1-2 題 LP。
- Loop：4-5 輪，2-3 輪 coding、1 輪 System Design（SDE II 以上）、1 輪 Bar Raiser（LP 為主）。每輪都夾 LP。
- Coding 題大多是 LeetCode Medium，SDE I 近期也有出現 graph / DP 的 Hard。

跟 Google 的差異（影響你怎麼練）：

| 面向 | Google | Amazon |
| --- | --- | --- |
| 題目來源 | 偏原創、陌生題 | 偏 LeetCode 高頻 tag 題，變形較少 |
| 重點 | 推導能力、invariant | 正確、乾淨、可跑，加上 edge case 與 follow-up |
| Behavioral | 一輪 Googleyness | 每輪都問，LP 佔分至少一半 |
| Design | 資深才有 | SDE II 以上必有，OA 就先考 |

## Priority Labels

- P0：Amazon 高頻，OA 和 phone screen 幾乎必碰。進 mock 前要能獨立完成。
- P1：loop 常見延伸，P0 穩定後補。
- P2：長尾與 SDE II 以上的 design-flavored 題。

## 由淺入深：五個 Tier

每個 Tier 內依「先易後難」排序。做到「30 分鐘內獨立寫完 + 3 個 edge cases + 能口述複雜度」才算過一題。

### Tier 1：熱身，Easy 為主（目標 2-3 天）

目的：把 Amazon 最愛的 hash / two pointers / stack / linked list 基本功打穩，同時練「先講 brute force 再優化」的口條。

| # | 題目 | Pattern | 為什麼 Amazon 愛考 |
| --- | --- | --- | --- |
| 1 | Two Sum | Hash Map | 開場題，追問 sorted 版、多解版 |
| 20 | Valid Parentheses | Stack | 追問多種括號、最少刪除 |
| 21 | Merge Two Sorted Lists | Linked List | 23 的前置 |
| 121 | Best Time to Buy and Sell Stock | One pass min | 追問 II、cooldown |
| 206 | Reverse Linked List | Linked List | 要能 iterative + recursive |
| 217 | Contains Duplicate | Hash Set | 追問 219 距離 k 內 |
| 242 | Valid Anagram | Counting | 49 的前置 |
| 704 | Binary Search | Binary Search | 追問 rotated |
| 733 | Flood Fill | Grid DFS | 200 的前置 |
| 819 | Most Common Word | String parse + Hash | Amazon 經典，考 parsing 細心 |
| 937 | Reorder Data in Log Files | Custom sort | Amazon 經典，考 comparator |
| 1710 | Maximum Units on a Truck | Greedy sort | Amazon 經典 OA 題 |

### Tier 2：Medium 核心，OA 主戰場（目標 1 週）

目的：Amazon OA 兩題幾乎都落在這一層。

| # | 題目 | Pattern | 備註 |
| --- | --- | --- | --- |
| 3 | Longest Substring Without Repeating Characters | Sliding Window | 你已練過 fixed window，這題是 variable window |
| 49 | Group Anagrams | Hash key design | key 用 sorted string 或 count array |
| 53 | Maximum Subarray | Kadane / Prefix | 追問回傳區間 |
| 56 | Merge Intervals | Sort + Sweep | 253 的前置 |
| 128 | Longest Consecutive Sequence | Hash Set | 要說明為什麼是 O(n) |
| 155 | Min Stack | Design | 兩個 stack 同步 |
| 200 | Number of Islands | Grid BFS/DFS | Amazon 出現頻率極高 |
| 238 | Product of Array Except Self | Prefix / Suffix | 追問 O(1) extra space |
| 347 | Top K Frequent Elements | Heap / Bucket | 692 的前置 |
| 394 | Decode String | Stack | 巢狀括號 |
| 560 | Subarray Sum Equals K | Prefix + Hash | 你已完成，拿來當 retell 練口條 |
| 692 | Top K Frequent Words | Heap + tie-break | comparator 要寫對 |
| 735 | Asteroid Collision | Stack | Amazon 高頻 |
| 763 | Partition Labels | Greedy last index | Amazon 高頻 |
| 973 | K Closest Points to Origin | Heap / Quickselect | Amazon 經典，追問 quickselect |
| 994 | Rotting Oranges | Multi-source BFS | 200 的延伸 |
| 1099 | Two Sum Less Than K | Sort + Two Pointers | Amazon 專屬 tag |
| 1268 | Search Suggestions System | Trie / Sort + Binary Search | Amazon 專屬高頻 |
| 1481 | Least Number of Unique Integers after K Removals | Counting + Greedy | OA 常見 |

### Tier 3：Medium 進階，phone screen / loop 常客（目標 1 週）

目的：進入 tree、graph、linked list 進階、design 的第一層。

| # | 題目 | Pattern | 備註 |
| --- | --- | --- | --- |
| 5 | Longest Palindromic Substring | Expand around center | 追問 Manacher 不用會，能講 O(n^2) 即可 |
| 15 | 3Sum | Sort + Two Pointers | 去重是重點 |
| 33 | Search in Rotated Sorted Array | Binary Search | 先判斷哪一半有序 |
| 98 | Validate Binary Search Tree | DFS with bounds | 不要只比 parent |
| 102 | Binary Tree Level Order Traversal | BFS | 103 zigzag 一起 |
| 138 | Copy List with Random Pointer | Hash / Interleave | Amazon 高頻 |
| 139 | Word Break | DP over string | 追問 140 回傳所有句子 |
| 146 | LRU Cache | Design: Hash + DLL | Amazon 最常考的 design 題 |
| 207 / 210 | Course Schedule I / II | Topological Sort | 要會 Kahn + DFS 兩種 |
| 215 | Kth Largest Element | Heap / Quickselect | 973 同款 |
| 236 | Lowest Common Ancestor | DFS return value | 你的 Google 題單也缺這題 |
| 253 | Meeting Rooms II | Sort + Min Heap | Amazon 高頻 |
| 322 | Coin Change | Unbounded Knapsack | DP 入門 gate |
| 380 | Insert Delete GetRandom O(1) | Design: Hash + Vector swap | 追問允許重複 381 |
| 543 | Diameter of Binary Tree | DFS return height | 124 的前置 |
| 572 | Subtree of Another Tree | Tree compare | 追問 serialize 解 |
| 621 | Task Scheduler | Greedy / Math | Amazon 高頻 |
| 767 | Reorganize String | Greedy + Heap | 621 同家族 |
| 863 | All Nodes Distance K in Binary Tree | Tree → Graph BFS | Amazon 高頻 |
| 1041 | Robot Bounded in Circle | Simulation | Amazon 專屬高頻 |
| 1152 | Analyze User Website Visit Pattern | Hash + Sort + enumerate | Amazon 專屬，考細心 |
| 1167 | Minimum Cost to Connect Sticks | Min Heap | Amazon 專屬 |

### Tier 4：Hard 與高難 Medium，loop 加分題（目標 1 週）

目的：SDE I 這層能講出正確方向就有加分；SDE II 要能寫完。

| # | 題目 | Pattern | 備註 |
| --- | --- | --- | --- |
| 23 | Merge k Sorted Lists | Heap / Divide & Conquer | 兩種都要會講 |
| 42 | Trapping Rain Water | Two Pointers / Mono Stack | Amazon 高頻 Hard |
| 76 | Minimum Window Substring | Sliding Window + Count | 3 的最終型 |
| 124 | Binary Tree Maximum Path Sum | DFS return single-branch | 543 的最終型 |
| 127 | Word Ladder | BFS on implicit graph | 追問雙向 BFS |
| 239 | Sliding Window Maximum | Monotonic Deque | deque 存 index |
| 295 | Find Median from Data Stream | Two Heaps | Amazon 高頻 |
| 297 | Serialize and Deserialize Binary Tree | DFS pre-order | 572 的延伸 |
| 460 | LFU Cache | Design: Hash + freq lists | 146 的延伸 |
| 472 | Concatenated Words | Trie / DP | Amazon 專屬高頻 |
| 588 | Design In-Memory File System | Design: Trie-like | Amazon 專屬 |
| 642 | Design Search Autocomplete System | Trie + Heap | 1268 的最終型 |
| 1192 | Critical Connections in a Network | Tarjan bridges | Amazon 專屬高頻 Hard |
| 1335 | Minimum Difficulty of a Job Schedule | 2D DP | Amazon 專屬 |
| 2402 | Meeting Rooms III | Two Heaps + simulation | 253 的最終型 |

### Tier 5：Amazon OA 風格題（穿插練，不需全做）

OA 題常是「披著業務故事的 LeetCode」：Prime Air 配送、倉儲包裹、伺服器負載、促銷折扣。要練的是「20 秒內剝掉故事看出 pattern」。

| # | 題目 | 對應 OA 故事 |
| --- | --- | --- |
| 1010 | Pairs of Songs With Total Durations Divisible by 60 | 你剛做完 974，同款 mod 計數 |
| 1099 | Two Sum Less Than K | Prime Air 兩包裹容量上限 |
| 1291 | Sequential Digits | 產生器 + 篩選 |
| 1648 | Sell Diminishing-Valued Colored Balls | 庫存最大收益，Binary Search on answer |
| 2104 | Sum of Subarray Ranges | Monotonic Stack 貢獻法 |
| 2214 | Minimum Health to Beat Game | Greedy |
| 2221 | Find Triangular Sum of an Array | Simulation |
| 2262 | Total Appeal of a String | 貢獻法 |
| 2281 | Sum of Total Strength of Wizards | Prefix of prefix + Mono Stack（Hard） |
| 2305 | Fair Distribution of Cookies | Backtracking / Bitmask |
| 2405 | Optimal Partition of String | Greedy |
| 2515 | Shortest Distance to Target String in a Circular Array | 模擬 |

## 通關 Gate（Amazon 版）

- Coding：每題 clarify → brute force → optimize → code → 自己出 3 個 edge cases 跑過。Amazon 面試官常要求「請你自己 walk through 一個 example」，不能只說「應該對」。
- Follow-up：每題至少準備一個 follow-up 答案（超大輸入、streaming、多執行緒、記憶體限制）。Amazon 喜歡在寫完後追問 scale。
- Design（SDE II）：每個 API 先講 target complexity，再講資料結構怎麼同步。146 / 380 / 588 / 642 都用這個框架講。
- LP：每輪 coding 前後預留 10 分鐘 behavioral，不要因此心慌。

## Leadership Principles 故事庫

Amazon 16 條 LP 中，coding 面試官最常問的 8 條與對應問法：

| LP | 常見問法 | 你要準備的故事 |
| --- | --- | --- |
| Customer Obsession | 為了用戶做過的困難取捨 | 一次犧牲工程便利換用戶體驗 |
| Ownership | 不是你的責任但你接了 | 跨組 bug、on-call 之外的修復 |
| Dive Deep | 找 root cause 的過程 | 一次難查的 bug，講 metrics 和 log |
| Bias for Action | 資訊不足時如何決策 | 快速 ship 後修正 |
| Invent and Simplify | 把複雜東西變簡單 | 重構、自動化、砍掉功能 |
| Earn Trust | 承認錯誤、與人不合 | 一次估錯 deadline 或 review 衝突 |
| Have Backbone; Disagree and Commit | 反對主管 / 團隊 | 提出反對、被否決後仍全力執行 |
| Deliver Results | 在壓力下交付 | 有數字的成果：latency、cost、time saved |

每個故事用 STAR + Reflection，Result 要有數字。同一個故事可以 cover 2-3 條 LP，先寫 6 個故事就夠輪替。

## 4 週衝刺（每天 75-90 分鐘）

- Week 1：Tier 1 全部 + Tier 2 前半（3, 49, 53, 56, 128, 155, 200, 238, 347）。每天穿插 1 題 Tier 5 練「剝故事」。開始寫 LP 故事 1-3。
- Week 2：Tier 2 後半 + Tier 3 前半（tree、linked list、146、253、322）。LP 故事 4-6。
- Week 3：Tier 3 後半 + Tier 4 的 23, 42, 76, 124, 127, 239, 295。模擬 OA：70 分鐘寫兩題陌生 Medium。
- Week 4：Tier 4 剩餘 + Mixed mock（每場 1 coding + 2 LP），連續 3 場最多 1 個小 bug。

## 跟現有訓練的銜接

- `profile.yaml` 目前在 Phase A（Enumeration / Prefix Sum / Hash Map），974 剛做完。Tier 1 的 1, 217, 242 和 Tier 2 的 49, 128, 560 可直接接上，不用切換 context。
- `mistakes.yaml` 的弱點（跳過 clarify、off-by-one）在 Amazon 更致命：OA 沒有面試官提醒，錯一個 edge case 就是 fail。每題強制先寫 3 個 edge case 再寫 code。
- 進度與錯誤照舊記到 `sessions/` 和 `mistakes.yaml`，pattern 標籤沿用 Google roadmap 的分群名稱。

## 不要做的事

- 不要只刷 Amazon tag 前 50 題就以為結束；OA 會換皮。
- 不要把 LP 留到最後一週，故事需要打磨。
- 不要在 OA Work Simulation 選「最像好人」的答案；用 LP 去推，通常是「先問清楚 / 先看資料 / 主動承擔」。
- 不要在 loop 裡沉默寫 code；Amazon 面試官會用「你有沒有邊寫邊講」當 Earn Trust 的訊號。
