//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
//
//示例 1：
//
//输入：board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "ABCCED"
//输出：true
//示例 2：
//
//输入：board = [["a", "b"], ["c", "d"]], word = "abcd"
//输出：false
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool locating(char** board, int boardSize, int boardColSize, int i, int j, int nums, char* word)
{
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word[nums])
        return false;
    if (nums == strlen(word) - 1)
        return true;
    board[i][j] = '\0';
    bool res = locating(board, boardSize, boardColSize, i + 1, j, nums + 1, word) ||
        locating(board, boardSize, boardColSize, i - 1, j, nums + 1, word) ||
        locating(board, boardSize, boardColSize, i, j + 1, nums + 1, word) ||
        locating(board, boardSize, boardColSize, i, j - 1, nums + 1, word);
    board[i][j] = word[nums];
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    int col = *boardColSize;
    int i = 0, j = 0;
    for (i = 0; i < boardSize; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (locating(board, boardSize, col, i, j, 0, word))
                return true;
        }
    }
    return false;
}