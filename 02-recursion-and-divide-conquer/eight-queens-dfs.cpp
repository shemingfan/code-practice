/**
 * ============================================================
 *  八皇后问题（Eight Queens Puzzle）—— 深度优先搜索（DFS）解法
 * ============================================================
 *
 *  问题描述：
 *      在 8×8 的国际象棋棋盘上摆放 8 个皇后，使得任意两个皇后都
 *      不能互相攻击。即要求：
 *          1) 每一行最多一个皇后；
 *          2) 每一列最多一个皇后；
 *          3) 每条主对角线（左上↘右下）最多一个皇后；
 *          4) 每条副对角线（右上↙左下）最多一个皇后。
 *
 *  算法思想（回溯法 = DFS + 剪枝）：
 *      按“行”逐行放置皇后，第 row 行尝试放到第 col 列：
 *          - 若该位置与前面已放好的皇后冲突，则剪枝，直接尝试下一列；
 *          - 若不冲突，则“落子”并递归进入 row + 1 行（深入下一层）；
 *          - 当 row == N 时，说明 8 个皇后全部合法放完，找到一个解；
 *          - 递归返回后“撤销落子”（回溯），继续尝试本行的其他列。
 *
 *      这个“选择 → 递归 → 撤销选择”的框架就是 DFS + 回溯的标准套路。
 *
 *  冲突判定技巧（O(1) 判定，把“扫描整行整列”变成“查表”）：
 *      - 列冲突：          colUsed[col]
 *      - 主对角线冲突：    左上→右下方向，同一条线上 row - col 恒定
 *                         偏移后下标为 row - col + (N - 1)，范围 [0, 2N-2]
 *      - 副对角线冲突：    右上→左下方向，同一条线上 row + col 恒定
 *                         下标为 row + col，范围 [0, 2N-2]
 *      由于我们按行推进，同一行天然只有一个皇后，无需额外判行冲突。
 *
 *  输出说明：
 *      - 共 92 个解（八皇后问题的经典答案）；
 *      - 若把旋转/镜像得到的解视为同一个“本质解”，则有 12 个。
 *      - 程序默认只打印前 MAX_PRINT 个解的棋盘图，避免刷屏。
 *
 *  编译运行（VS Code 集成终端 / g++）：
 *      g++ -std=c++11 -O2 -o eight_queens_dfs eight_queens_dfs.cpp
 *      ./eight_queens_dfs        (Windows: .\eight_queens_dfs.exe)
 *      注：本机 g++ 为 4.9.2，最高支持 -std=c++11；
 *          若你的编译器较新，用 -std=c++17 亦可。
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ----------------------------- 全局状态 -----------------------------

int N = 8;                      // 棋盘阶数，八皇后问题即 N = 8
long long solutionCount = 0;    // 已找到的合法解总数
int printCount = 0;             // 已经打印过的解的数量
const int MAX_PRINT = 3;        // 最多打印几个解的棋盘图（防止刷屏）

vector<int> queenCol;           // queenCol[row] = col，表示第 row 行的皇后放在第 col 列
vector<bool> colUsed;           // colUsed[col]：第 col 列是否已被占用
vector<bool> mainDiagUsed;      // 主对角线（row - col 为常数）是否已被占用
vector<bool> antiDiagUsed;      // 副对角线（row + col 为常数）是否已被占用

// --------------------------- 打印棋盘 -------------------------------

/**
 * 把当前找到的解以棋盘的图形方式打印出来。
 * 'Q' 表示皇后，'.' 表示空格。
 */
void printBoard() {
    cout << "解 #" << solutionCount << " ：\n";
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cout << (queenCol[row] == col ? "Q " : ". ");
        }
        cout << '\n';
    }
    // 额外输出该解的列下标序列，便于和标准答案对照
    cout << "列位置: ";
    for (int row = 0; row < N; ++row) {
        cout << queenCol[row] + 1;          // 用 1 开始计数，更符合人类习惯
        if (row != N - 1) cout << ' ';
    }
    cout << "\n\n";
}

// ------------------------ 深度优先搜索主体 ---------------------------

/**
 * DFS：尝试为第 row 行放置一个皇后。
 *
 * @param row 当前正在处理的行号，范围 [0, N]
 *            当 row == N 时表示 0 ~ N-1 行都已放好，得到一个完整解。
 *
 * 时间复杂度：最坏 O(N!)，但在列/对角线剪枝下实际搜索空间远小于此；
 *             N = 8 时几乎瞬间完成。
 * 空间复杂度：O(N)，来自递归栈深度与三个标记数组。
 */
void dfs(int row) {
    // ---------- 递归边界：所有行都放好了，记录并输出一个解 ----------
    if (row == N) {
        ++solutionCount;
        if (printCount < MAX_PRINT) {       // 只打印前若干个解的棋盘
            printBoard();
            ++printCount;
        }
        return;                             // 回溯：返回上一行继续尝试
    }

    // ---------- 在第 row 行中从左到右尝试每一个列 ----------
    for (int col = 0; col < N; ++col) {
        // 计算两个对角线的下标（+N-1 是为了把 row-col 的负值偏移成非负下标）
        int mainDiag = row - col + (N - 1); // 主对角线：row - col 恒定
        int antiDiag = row + col;           // 副对角线：row + col 恒定

        // ---------- 剪枝：只要有一项冲突，这个位置就不能放 ----------
        if (colUsed[col] || mainDiagUsed[mainDiag] || antiDiagUsed[antiDiag]) {
            continue;                       // 尝试本行的下一列
        }

        // ---------- 选择：把皇后放在 (row, col) ----------
        queenCol[row] = col;
        colUsed[col] = true;
        mainDiagUsed[mainDiag] = true;
        antiDiagUsed[antiDiag] = true;

        // ---------- 深入：递归处理下一行 ----------
        dfs(row + 1);

        // ---------- 撤销选择（回溯）：恢复现场，以便尝试其他列 ----------
        colUsed[col] = false;
        mainDiagUsed[mainDiag] = false;
        antiDiagUsed[antiDiag] = false;
    }
    // 本行所有列都试过仍无解，自然返回，由上一层继续尝试
}

// ------------------------------ 主函数 ------------------------------

int main() {
    cout << "===== 八皇后问题（深度优先搜索 / 回溯法）=====\n\n";

    // 初始化数组：列 2N-1 条对角线各需一个标记位
    queenCol.assign(N, -1);
    colUsed.assign(N, false);
    mainDiagUsed.assign(2 * N - 1, false);
    antiDiagUsed.assign(2 * N - 1, false);

    dfs(0);                 // 从第 0 行开始搜索

    cout << "搜索完成：N = " << N
         << " 时共有 " << solutionCount << " 个解。\n";
    cout << "（其中互为旋转/镜像的视为同一个本质解时，共有 12 个本质解）\n";

    return 0;
}
