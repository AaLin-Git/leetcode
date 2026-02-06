/* You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value
and return this value. Any answer with a calculation error less than 10-5 will be accepted. */

#include "../leetcode.h"

double findMaxAverage(int* nums, int size, int k)
{
    int left = 0;
    int right = k;
    double sum = 0;
    double average = 0;
    double max_sum = 0;
    int i = 0;

    while (i < k)
    {
        sum += nums[i];
        i++;
    }
    max_sum = sum;

    while (right < size)
    {
        sum -= nums[left];
        sum += nums[right];
        left++;
        right++;
        if (sum > max_sum)
            max_sum = sum;
    }
    average = max_sum / k;
    return (average);
}

int main(void)
{
    int arr[] = {3,3,4,3,0};
	int n = sizeof(arr) / sizeof(arr[0]);;
    double res = findMaxAverage(arr, n, 3);
    printf("Maximum average is %f\n", res);
    return (0);
}
