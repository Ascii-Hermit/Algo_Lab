#include <stdio.h>
#include <stdlib.h>
// void merge(int *arr, int start, int mid, int end)
// {
//     if (sizeof(arr) / sizeof(arr[0])<2){
//         return;
//     }
//     for (int i = start; i < end;i++){
//         if
//     }
// }

// void mergeSort(int *arr, int start, int end)
// {
//     if (start < end)
//     {
//         int mid = (start + end) / 2;
//         mergeSort(arr, start, mid);
//         mergeSort(arr, mid + 1, end);
//         merge(arr, start, mid, end);
//     }
// }

#include <stdio.h>

// Merge two sorted subarrays and print inversions
// void merge_and_print(int arr[], int temp[], int left, int mid, int right)
// {
//     int i = left, j = mid + 1, k = left;

//     while (i <= mid && j <= right)
//     {
//         if (arr[i] < arr[j])
//         {
//             printf("(%d, %d)\n", arr[i], arr[j]);
//             j++;
//         }
//         else
//         {
//             i++;
//         }
//     }
// }

// count number of zeros
// int count = 0;
// void merge_andcount(int *arr, int start, int mid, int end)
// {
//     int i = start;
//     int j = mid + 1;
//     if (end - start == 1)
//     {
//         while (i <= mid && j <= end)
//         {
//             printf("in");
//             if (arr[i] == 0)
//             {
//                 count++;
//                 i++;
//             }
//             else
//             {
//                 i++;
//             }
//             if (arr[j] == 0)
//             {
//                 count++;
//                 j++;
//             }
//             else
//             {
//                 j++;
//             }
//         }
//     }
// }

// Merge sort the array and print inversions
// void merge_sort_and_print(int arr[], int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         merge_sort_and_print(arr, left, mid);
//         merge_sort_and_print(arr, mid + 1, right);
//         merge_andcount(arr, left, mid, right);
//     }
// }

// Function to print inversions in an array using divide and conquer
// void print_inversions(int arr[], int n)
// {
//     int temp[n];
//     merge_sort_and_print(arr, temp, 0, n - 1);
// }

// int main()
// {
//     int arr[] = {1, 0, 1, 0, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     // printf("Inverted pairs:\n");
//     // print_inversions(arr, n);
//     merge_sort_and_print(arr, 0, n);
//     printf("Number of zeros: %d", count);
//     return 0;
// }

// int main()
// {
//     int size = 5;
//     int *arr = malloc(size * sizeof(int));
//     arr[0] = 9;
//     arr[1] = 2;
//     arr[2] = 5;
//     arr[3] = 1;
//     arr[4] = 7;
//     // bubbleSort(arr, size);
//     // selectionSort(arr, size);
//     // insertionSort(arr, size);
//     // mergeSort(arr, 0, size - 1); // remember its size - 1
//     print_inversions(arr, size);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d,", arr[i]);
//     }
// }

int sum = 0;
int merge_sort(int *arr, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = (start + end) / 2;
    int left_sum = merge_sort(arr, start, mid);
    int right_sum = merge_sort(arr, mid + 1, end);
    sum = right_sum + left_sum;
}

int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));
    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 6;
    arr[3] = 2;
    arr[4] = 8;
    merge_sort(arr, 0, 4);
    printf("%d", sum);
}
