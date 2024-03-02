#include <stdio.h>

int merge(int arr[], int left, int mid, int right)
{
    int inversions = 0;
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inversions += (mid - left + 1) - i;
            printf("(%d, %d),", L[i], R[j - 1]); // this is the logic that prints the inversions, for every element in the array in front of
                                                 // the current element, if its larger simply print it.
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversions;
}

int count_inversions(int arr[], int left, int right)
{
    int inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inversions += count_inversions(arr, left, mid);
        inversions += count_inversions(arr, mid + 1, right);
        inversions += merge(arr, left, mid, right);
    }
    return inversions;
}

int main()
{
    int arr[] = {1, 6, 5, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_inversions = count_inversions(arr, 0, n - 1);
    printf("Number of inversions: %d\n", num_inversions);
    return 0;
}
