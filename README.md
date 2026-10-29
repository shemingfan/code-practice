# C++ 练习代码

平时做算法题和课程作业时写的 C++ 代码，按主题整理归档。

大多来自 Dev-C++ 手写练习，代码风格不统一、注释有多有少，保留原始写法便于日后对比思路变化。

## 目录结构

```
cpp-practice/
├── 01-oop-and-syntax/                面向对象与语法
├── 02-recursion-and-divide-conquer/  递归与分治
├── 03-number-theory-and-bigint/      数论与高精度
├── 04-string-and-simulation/         字符串与模拟
└── 99-unfinished/                    未完成的半成品
```

## 01-oop-and-syntax 面向对象与语法

| 文件 | 内容 |
| --- | --- |
| `circle-class.cpp` | **圆类 Circle**：输入半径求周长与面积，再按单位价格计算围栏、水泥费用（const 常量 + 类成员函数） |
| `student-struct.cpp` | **结构体 + 指针**：`student` 结构体存学号与两门成绩，按总分和折算成绩判断是否「Excellent」 |
| `table-class.cpp` | **数据表模拟**：`table` 类，支持建表、增删列、增删记录、按字段查询、打印整表 |
| `table-class-assignment.cpp` | **数据表模拟（作业提交版）**：同题，功能更完整、中文注释更详细，带输入校验 |

## 02-recursion-and-divide-conquer 递归与分治

| 文件 | 内容 |
| --- | --- |
| `hanoi.cpp` | **汉诺塔**：经典递归，打印每一步的移动过程 |
| `eight-queens-dfs.cpp` | **八皇后**：DFS 回溯逐行搜索，打印全部解与对应列位置 |
| `fractal-matrix.cpp` | **分治填方阵**：输入 n，构造 2ⁿ × 2ⁿ 矩阵，递归把每个子块左上角逐层置 0 |
| `quick-select.cpp` | **快速选择**：分治求第 k 小，按首元素 pivot 分组后只递归所在的一侧 |

## 03-number-theory-and-bigint 数论与高精度

| 文件 | 内容 |
| --- | --- |
| `linear-sieve.cpp` | **线性筛（欧拉筛）**：标记数组求 1..n 内的全部质数 |
| `linear-sieve-commented.cpp` | 同 `linear-sieve.cpp`，带逐行中文注释的版本 |
| `palindrome-prime.cpp` | **回文质数**：线性筛 + 回文判定 |
| `prime-filter.cpp` | **筛法应用**：先筛出 1e5 内质数，再从读入的 n 个数中挑出质数输出 |
| `leap-year-count.cpp` | **闰年统计**：统计区间 [x, y] 内闰年个数并全部输出 |
| `bigint-factorial-sum.cpp` | **大数阶乘求和**：高精度模拟计算 1! + 2! + ... + n! |
| `bigint-factorial-sum-commented.cpp` | 同 `bigint-factorial-sum.cpp`，带完整中文文档头（程序名 / 功能 / 样例） |

## 04-string-and-simulation 字符串与模拟

| 文件 | 内容 |
| --- | --- |
| `document-editor-kmp.cpp` | **文档编辑器**：维护一个字符数组，支持尾部追加、截取片段指定位置插入，并用 **KMP** 查找子串首次出现位置 |
| `minesweeper-count.cpp` | **扫雷计数**：输入 n × m 雷区，`*` 原样输出，其余格子输出周围八格雷数 |
| `tree-removal.cpp` | **校门外的树**：给若干被移除的区间，统计剩下的树（区间标记思想） |

## 99-unfinished 半成品

| 文件 | 说明 |
| --- | --- |
| `input-skeleton.cpp` | 只读入 `n` 就结束了，是个没写完的空壳，留着占位 |

## 与原始文件名的对照

整理前的文件名大多是 `1.cpp`、`17.cpp` 这类编号，重新命名后的对应关系：

| 原名 | 现路径 |
| --- | --- |
| `1.cpp` | `01-oop-and-syntax/circle-class.cpp` |
| `structure.cpp` | `01-oop-and-syntax/student-struct.cpp` |
| `database.cpp` | `01-oop-and-syntax/table-class.cpp` |
| `作业.cpp` | `01-oop-and-syntax/table-class-assignment.cpp` |
| `hanoi.cpp` | `02-recursion-and-divide-conquer/hanoi.cpp` |
| `eight_queens_dfs.cpp` | `02-recursion-and-divide-conquer/eight-queens-dfs.cpp` |
| `17.cpp` | `02-recursion-and-divide-conquer/fractal-matrix.cpp` |
| `18.cpp` | `02-recursion-and-divide-conquer/quick-select.cpp` |
| `prime.cpp` | `03-number-theory-and-bigint/linear-sieve.cpp` |
| `prime().cpp` | `03-number-theory-and-bigint/linear-sieve-commented.cpp` |
| `palindrome prime.cpp` | `03-number-theory-and-bigint/palindrome-prime.cpp` |
| `3.cpp` | `03-number-theory-and-bigint/prime-filter.cpp` |
| `4.cpp` | `03-number-theory-and-bigint/leap-year-count.cpp` |
| `high.cpp` | `03-number-theory-and-bigint/bigint-factorial-sum.cpp` |
| `high().cpp` | `03-number-theory-and-bigint/bigint-factorial-sum-commented.cpp` |
| `10.cpp` | `04-string-and-simulation/document-editor-kmp.cpp` |
| `13.cpp` | `04-string-and-simulation/minesweeper-count.cpp` |
| `hello.cpp` | `04-string-and-simulation/tree-removal.cpp` |
| `2.cpp` | `99-unfinished/input-skeleton.cpp` |

有几组是同一题的不同版本，以后可以合并：`linear-sieve` ↔ `-commented`、`bigint-factorial-sum` ↔ `-commented`、`table-class` ↔ `-assignment`。

## 编译与运行

需要 C++11 及以上（用到 `vector`、`auto`、范围 `for`）。

```bash
g++ -std=c++17 -O2 "03-number-theory-and-bigint/linear-sieve.cpp" -o linear-sieve
./linear-sieve
```

用 Dev-C++ 直接打开 `.cpp` 文件按 F11 即可。仓库不包含编译产物（`.exe`、`output/` 等已在 `.gitignore` 中排除）。

## 编码约定

源文件统一为 **UTF-8（无 BOM）**、LF 换行，保证在 GitHub 网页和 Linux 下中文注释都不乱码。
