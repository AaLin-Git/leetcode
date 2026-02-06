/* Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order. */

#include "../leetcode.h"
#include <stdlib.h>

int square(int num)
{
    return (num * num);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    int i = numsSize - 1;
    int leftnum = 0;
    int rightnum = 0;
    
    int *arr = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    while (i >= 0)
    {
        leftnum = square(nums[left]);
        rightnum = square(nums[right]);
        if (leftnum > rightnum)
        {
            arr[i] = leftnum;
            left++;
        }
        else
        {
            arr[i] = rightnum;
            right--;
        }
        i--;
    }
    return (arr);
}

int main(void)
{
    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int returnSize = 0;
    int *result;
    int i;

    result = sortedSquares(arr, n, &returnSize);
    printf("Sorted squares: ");
    for (i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return (0);
}
