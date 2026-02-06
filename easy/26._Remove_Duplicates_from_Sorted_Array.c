/* Given an integer array nums sorted in non-decreasing order, remove the duplicates 
in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. 
After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. 
The remaining elements beyond index k - 1 can be ignored. */

#include "../leetcode.h"

int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int slow = 0;
    int fast = 1;

    while (fast <= numsSize - 1)
    {
        if (nums[slow] < nums[fast])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    slow++;
    return (slow);
}

int main(void)
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
	int n = sizeof(arr) / sizeof(arr[0]);;
    double res = removeDuplicates(arr, n);
	printf("Array with unique numbers: ");
	for (int i = 0; i < res; i++)
		printf("%i ", arr[i]);
	printf("\n");
    return (0);
}
