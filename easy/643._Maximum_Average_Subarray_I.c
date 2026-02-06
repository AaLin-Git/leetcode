#include <stdio.h>

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
    // int arr[] = {5};
	int n = sizeof(arr) / sizeof(arr[0]);;
    double res = findMaxAverage(arr, n, 3);
    printf("res = %f\n", res);
    return (0);
}
