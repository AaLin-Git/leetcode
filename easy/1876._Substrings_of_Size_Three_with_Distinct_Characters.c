/* A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string. */

#include "../leetcode.h"
#include <string.h>

int is_unique(char c1, char c2, char c3)
{
    int i = 0;
    if (c1 == c2
        || c1 == c3
        || c2 == c3)
        return (0);
    return (1);
}

int countGoodSubstrings(char* s)
{
    int left = 0;
    int right = 2;
    int count = 0;
    int len = strlen(s);
    
    if (len < 3)
        return (0);
    while (s[left] && s[right] != '\0')
    {
        if (is_unique(s[left], s[left + 1], s[left + 2]))
            count++;
        left++;
        right++;
    }
    return (count);
}

int main(void)
{
    char *str = "aababcabc";
    int res = countGoodSubstrings(str);
    printf("There are %d good substrings of size 3\n", res);
    return (0);
}
