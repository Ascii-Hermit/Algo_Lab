#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int start, int mid, int end)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;

    int left_arr[left_size];
    int right_arr[right_size];

    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}

int partition(int *arr, int start, int end)
{
    int i = start - 1;
    int pivot = end;
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

void quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

int binary_search_constnum(int *arr, int start, int end)
{
    int count = 0;
    if (start == end)
    {
        if (arr[end] == 0)
        {
            count++;
        }
        return count;
    }
    if (arr[end] == 0)
    {
        count++;
        binary_search_constnum(arr, start, end - 1);
    }
    else
    {
        binary_search_constnum(arr, start, end - 1);
    }
}

int binary_search_constfact(int *arr, int start, int end)
{
    if (start == end)
    {
        return !arr[end];
    }
    if (arr[end] == 0 && arr[end - 1] == 1)
    {
        return end;
    }
    else
    {
        int mid = (start + end) / 2;
        if (arr[end])
            binary_search_constfact(arr, start, mid);
        else
            binary_search_constfact(arr, mid + 1, end);
    }
}

void insertion_sort(int *arr, int start, int end)
{
    int index = 0;
    for (int i = index + 1; i < end + 1; i++)
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

void selection_sort(int *arr, int start, int end)
{
    int min_val = 999;
    int min_ind = 999;
    int index = start;
    while (index < end)
    {
        for (int i = index; i < end + 1; i++)
        {
            if (arr[i] < min_val)
            {
                min_ind = i;
                min_val = arr[i];
            }
        }
        swap(arr, min_ind, index);
        index++;
        min_val = 999;
    }
}

int bruteforce_matching(int *arr, int *ptr, int arr_size, int ptr_size)
{
    for (int i = 0; i < arr_size - ptr_size; i++)
    {
        int j = 0;
        for (; j < ptr_size; j++)
        {
            if (arr[i + j] != ptr[j])
            {
                break;
            }
        }
        if (j == ptr_size - 1)
        {
            return i;
        }
    }
}

void bubblesort(int *arr, int start, int end)
{
    for (int i = 0; i < end; i++)
    {
        for (int j = i + 1; j < end + 1; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }
}

int main()
{
    int *arr = malloc(sizeof(int) * 5);

    arr[0] = 9;
    arr[1] = 8;
    arr[2] = 1;
    arr[3] = 7;
    arr[4] = 4;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    quicksort(arr, 0, 4);
    // bubblesort(arr, 0, 5);
    //  insertion_sort(arr, 0, 4);
    //  int count = bruteforce_matching(arr, ptr, 5, 2);
    //  printf("%d\n", count);

    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}