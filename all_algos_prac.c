#include <stdio.h>
#include <stdlib.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }
}
void selectionSort(int *arr, int size)
{
    int index = 0;
    int min_val = 99;
    int min_index = 99;
    while (index < size)
    {
        for (int i = index; i < size; i++)
        {
            if (min_val > arr[i])
            {
                min_val = arr[i];
                min_index = i;
            }
        }
        swap(arr, min_index, index);
        index = index + 1;
        min_val = 99;
    }
}
void insertionSort(int *arr, int size)
{
    int index = 0;
    for (int i = index + 1; i < size; i++)
    {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = val;
    }
}
void merge(int *arr, int start, int mid, int end)
{
    int left_arr_size = (mid - start + 1);
    int right_arr_size = (end - mid);
    int left_arr[left_arr_size];
    int right_arr[right_arr_size];
    for (int i = 0; i < mid; i++)
    {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < end; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = start; // important

    while (i < left_arr_size && j < right_arr_size)
    {
        if (left_arr[i] > right_arr[j])
        {
            arr[k] = right_arr[j];
            j = j + 1;
        }
        else
        {
            arr[k] = left_arr[i];
            i = i + 1;
        }
        k++;
    }
    while (i < left_arr_size)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }
    while (j < right_arr_size)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
}
void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int partition(int *arr, int start, int end)
{
    int pivot = end;
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, pivot);
    return i + 1;
}
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}
int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));
    arr[0] = 9;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 1;
    arr[4] = 7;
    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // mergeSort(arr, 0, size - 1); // remember its size - 1
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
}
