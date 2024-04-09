#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Function to find the maximum of three integers
int max(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    if (b > a && b > c)
    {
        return b;
    }
    return c;
}

// Function to find the maximum contiguous subarray crossing the middle index
int maxCrossingSubarray(int arr[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum >= left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum >= right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

// Function to find the maximum contiguous subarray using divide and conquer
int maxSubarray(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    // Find maximum subarray sum in left half, right half, and across the middle
    int left_max = maxSubarray(arr, low, mid);
    int right_max = maxSubarray(arr, mid + 1, high);
    int cross_max = maxCrossingSubarray(arr, low, mid, high);

    // Return the maximum of the three
    return max(left_max, right_max, cross_max);
}

int sum_val(int *arr, int i, int j)
{
    int sum = 0;
    for (; i <= j; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int kadane(int *arr, int start, int end)
{
    int max_current = arr[0];
    int max_global = arr[0];
    int size = end - start + 1;
    for (int i = 1; i < size; i++)
    {
        max_current = (arr[i] >= arr[i] + max_current ? arr[i] : arr[i] + max_current);
        if (max_current > max_global)
        {
            max_global = max_current;
        }
        printf("For %d the max_current val is %d max_global val is %d \n", i, max_current, max_global);
    }
    return max_global;
}
int main()
{
    int *arr = (int *)malloc(8 * sizeof(int));
    arr[0] = -1;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 1;
    arr[5] = 5;
    arr[6] = -1;
    arr[7] = -2;
    arr[7] = -2;
    arr[7] = 16;
    int all_sum = sum_val(arr, 0, 7);
    printf("%d", kadane(arr, 0, 7));
    printf("\n%d", maxSubarray(arr, 0, 7));
}