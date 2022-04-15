//在一个 n* m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//

//示例:
//
//现有矩阵 matrix 如下：
//
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//给定 target  = 5，返回 true。
//
//给定 target  = 20，返回 false。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*
 * 输入 **matrix 是长度为 matrixSize 的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *matrixColSize 数组作为另一输入，*matrixColSize 数组的长度也为 matrixSize
 */

bool BinarySearch(int* cur, int n, int target)
{
    int low = 0, hight = n - 1;
    int mid = 0;
    while (low <= hight)
    {
        mid = (low + hight) / 2;
        if (target < cur[mid])
            hight = mid - 1;
        else if (target > cur[mid])
            low = mid + 1;
        else
            return true;
    }
    return false;
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int i = 0;
    for (i = 0; i < matrixSize; ++i)
    {
        if (BinarySearch(matrix[i], *matrixColSize, target))
            return true;
    }
    return false;
}