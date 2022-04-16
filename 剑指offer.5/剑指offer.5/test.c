//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//示例 1：
//
//输入：s = "We are happy."
//输出："We%20are%20happy."
//
//
//限制：
//
//0 <= s 的长度 <= 10000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

char* replaceSpace(char* s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    int len = strlen(s) + 2 * count;
    char* answer = malloc(sizeof(char) * len + 1);
    for (int i = 0, j = 0; i < strlen(s); i++, j++)
    {
        if (s[i] == ' ')
        {
            answer[j] = '%';
            answer[++j] = '2';
            answer[++j] = '0';
        }
        else
        {
            answer[j] = s[i];
        }
    }
    answer[len] = '\0';
    return answer;
}