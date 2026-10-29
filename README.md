# C++ 练习代码

平时做算法题和课程作业时写的 C++ 代码，按主题整理归档。

代码来自两个地方（桌面的 Dev-C++ 作业目录和 `_aidlux` 目录），合并时已去掉内容重复的部分。风格不统一、注释有多有少，保留原始写法便于日后对比思路变化。

## 目录结构

```
cpp-practice/
├── 01-oop-and-syntax/                面向对象、结构体、指针
├── 02-recursion-and-divide-conquer/  递归与分治
├── 03-number-theory-and-bigint/      数论与高精度
├── 04-string-and-simulation/         字符串处理
├── 05-array-and-simulation/          数组与模拟
├── 06-sorting-and-greedy/            排序与贪心
└── 99-unfinished/                    未完成的半成品
```

## 01-oop-and-syntax 面向对象与语法

| 文件 | 内容 |
| --- | --- |
| `circle-class.cpp` | **圆类 Circle**：输入半径求周长与面积，再按单位价格计算围栏、水泥费用 |
| `student-struct.cpp` | **结构体 + 指针**：按总分与折算成绩判断是否「Excellent」 |
| `table-class.cpp` | **数据表模拟**：建表、增删列、增删记录、按字段查询、打印整表 |
| `table-class-assignment.cpp` | **数据表模拟（作业提交版）**：同题，功能更完整、中文注释更详细 |
| `pointer-max.cpp` | **指针遍历**：用指针推进的方式读入数组并求最大值，注释里讲了指针与解引用 |
| `reference-rotate.cpp` | **引用参数**：通过引用实现三个数的循环移位 |
| `struct-sort-top5.cpp` | **结构体排序**：自定义 `cmp` 按总分 → 语文 → 学号排序，输出前 5 名 |

## 02-recursion-and-divide-conquer 递归与分治

| 文件 | 内容 |
| --- | --- |
| `hanoi.cpp` | **汉诺塔**：经典递归，带输入提示 |
| `hanoi-alt.cpp` | **汉诺塔（另一种写法）**：`move` / `hanoi` 职责分离得更彻底 |
| `eight-queens-dfs.cpp` | **八皇后**：DFS 回溯逐行搜索，打印全部解与列位置 |
| `fractal-matrix.cpp` | **分治填方阵**：构造 2ⁿ × 2ⁿ 矩阵，递归把子块左上角逐层置 0 |
| `quick-select.cpp` | **快速选择**：分治求第 k 小，只递归所在的一侧 |
| `factorial-recursive.cpp` | **递归阶乘** |

## 03-number-theory-and-bigint 数论与高精度

| 文件 | 内容 |
| --- | --- |
| `linear-sieve.cpp` | **线性筛（欧拉筛）**：求 1..n 内全部质数 |
| `linear-sieve-commented.cpp` | 同上的逐行中文注释版 |
| `linear-sieve-prefix-sum.cpp` | **筛法 + 累加**：从最小的质数开始累加，输出和不超过 n 的所有质数 |
| `palindrome-prime.cpp` | **回文质数**：线性筛 + 回文判定 |
| `prime-filter.cpp` | **筛法应用**：先筛出 1e5 内质数，再从读入的 n 个数中挑出质数 |
| `leap-year-count.cpp` | **闰年统计**：统计区间 [x, y] 内闰年个数并全部输出 |
| `bigint-factorial-sum.cpp` | **大数阶乘求和**：高精度计算 1! + 2! + ... + n! |
| `bigint-factorial-sum-commented.cpp` | 同上的文档注释版（程序名 / 功能 / 样例） |

## 04-string-and-simulation 字符串处理

| 文件 | 内容 |
| --- | --- |
| `document-editor-kmp.cpp` | **文档编辑器**：尾部追加、截取片段、指定位置插入，并用 **KMP** 查子串首次位置 |
| `uppercase-string.cpp` | **转大写**：把字符串里的小写字母统一转成大写 |
| `caesar-cipher.cpp` | **凯撒密码**：整串字母按 n 位移 |
| `expression-length.cpp` | **算式长度**：按 `a`/`b`/`c` 指令做加、减、乘，输出算式和字符长度 |
| `char-count.cpp` | **字符计数**：统计字符串中非空格字符的个数 |
| `lucky-word.cpp` | **笨小猴**：统计字母出现次数的极差，判断是否为质数 |

## 05-array-and-simulation 数组与模拟

| 文件 | 内容 |
| --- | --- |
| `minesweeper-count.cpp` | **扫雷计数**：`*` 原样输出，其余格子输出周围八格雷数 |
| `minesweeper-count-v2.cpp` | **扫雷（另一版）**：格子自身也计入统计，边界处理略有不同 |
| `tree-removal.cpp` | **校门外的树**：给若干被移除区间，统计剩下的树 |
| `triple-pair-count.cpp` | **相似三元组**：统计两两三维差 ≤5 且总和差 ≤10 的对数 |
| `cuboid-cut-volume.cpp` | **挖洞体积**：三维空间被 q 个长方体挖掉后剩余格子数 |
| `number-overlap-stats.cpp` | **数字重叠统计**：与标准 7 个数逐一比对，统计相同个数为 1..7 的分布 |
| `pingpong-score.cpp` | **乒乓球比分**：按 11 分制和 21 分制分别输出 |
| `maze-chase.cpp` | **迷宫追逐**：10×10 网格中两角色顺指针方向轮转移动，计步或判定无法相遇 |
| `similar-scores.cpp` | **相似成绩**：两两比较三科成绩与总分，输出符合条件的学生对 |
| `subset-sum-doubling.cpp` | **倍数求和**：读入若干数求总和，再乘 2ⁿ⁻¹ |
| `vote-longest.cpp` | **投票**：取出最长且字典序最大的投票串，输出对应序号与原串 |
| `jolly-jumper.cpp` | **Jolly Jumper**：判断相邻差是否恰好覆盖 1..n-1 |

## 06-sorting-and-greedy 排序与贪心

| 文件 | 内容 |
| --- | --- |
| `sort-numbers.cpp` | **排序输出**：读入 m 个数升序输出 |
| `dedupe-sorted.cpp` | **排序去重**：排序后原地去重，输出个数和结果 |
| `greedy-max-count.cpp` | **贪心选取**：从大到小累加，凑到目标值所需的最少个数 |
| `bubble-swap-count.cpp` | **冒泡排序**：统计排序过程中的交换次数 |
| `score-line-cutoff.cpp` | **分数线**：按 m × 1.5 划出分数线并输出晋级名单 |
| `judge-scoring.cpp` | **评委打分**：去掉最高最低分求平均，输出选手最高分 |

## 99-unfinished 半成品

| 文件 | 说明 |
| --- | --- |
| `input-skeleton.cpp` | 只读入 `n` 就结束了，是个没写完的空壳，留着占位 |

## 合并时去掉的重复文件

以下 5 个文件与仓库中已有代码**忽略空白后完全一致**，未重复收录：

| 原路径 | 与谁重复 |
| --- | --- |
| `_aidlux/10.cpp` | `04-string-and-simulation/document-editor-kmp.cpp` |
| `_aidlux/structure.cpp` | `01-oop-and-syntax/student-struct.cpp` |
| `_aidlux/2.cpp` | `05-array-and-simulation/tree-removal.cpp`（校门外的树） |
| `_aidlux/divide.cpp` | `02-recursion-and-divide-conquer/quick-select.cpp` |
| `_aidlux/high.cpp` | `03-number-theory-and-bigint/bigint-factorial-sum.cpp` |

## 同题不同解法（都保留）

| 题目 | 文件 |
| --- | --- |
| 汉诺塔 | `hanoi.cpp` / `hanoi-alt.cpp` |
| 线性筛 | `linear-sieve.cpp` / `linear-sieve-commented.cpp` / `linear-sieve-prefix-sum.cpp` |
| 扫雷 | `minesweeper-count.cpp` / `minesweeper-count-v2.cpp` |
| 大数阶乘求和 | `bigint-factorial-sum.cpp` / `bigint-factorial-sum-commented.cpp` |
| 数据表模拟 | `table-class.cpp` / `table-class-assignment.cpp` |

## 编译与运行

需要 C++11 及以上（用到 `vector`、`auto`、范围 `for`）。

```bash
g++ -std=c++17 -O2 "03-number-theory-and-bigint/linear-sieve.cpp" -o linear-sieve
./linear-sieve
```

用 Dev-C++ 直接打开 `.cpp` 文件按 F11 即可。仓库不包含编译产物（`.exe`、`output/` 等已在 `.gitignore` 中排除）。

## 编码约定

源文件统一为 **UTF-8（无 BOM）**、LF 换行，保证在 GitHub 网页和 Linux 下中文注释都不乱码。
