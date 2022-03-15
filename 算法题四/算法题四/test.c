

//实现 strStr() 函数。
//
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  - 1 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-strstr
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//难度：简单

int strStr(const char* haystack, const char* needle)
{
    assert(haystack && needle);
    const char* s1 = NULL;
    const char* s2 = NULL;
    char* cmp = haystack;
    int i = 0;

    if (*haystack == '\0' && *needle == '\0')
    {
        return 0;
    }
    while (*cmp)
    {
        const x = i++;
        s1 = cmp;
        s2 = needle;
        while (*s1 && *s2 && (*s1 == *s2))
        {
            s1++;
            s2++;

        }
        if (*s2 == '\0')
        {
            return x;
        }
        cmp++;
    }
    return -1;
}