/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container. */

#include "../leetcode.h"

int multiply(int left, int right, int distance)
{
    if (left <= right)
        return (left * distance);
    else
        return (right * distance);
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int distance = 0;
    int res = 0;
    int compare;

    while (left < right)
    {
        distance = right - left;
        compare = multiply(height[left], height[right], distance);
        if (compare > res)
            res = compare;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return (res);
}

int main(void)
{
    int height[] = {1,8,6,2,5,4,8,3,7};
	int n = sizeof(height) / sizeof(height[0]);;
    int res = maxArea(height, n);
    printf("The max area of water the container can contain is %d\n", res);
    return (0);
}