#include <stdio.h>
#include <stdlib.h>
int sum = 0;
int count = 0;

int decrease_count(int *arr, int start, int end, int index)
{
    if (index >= start)
    {
        if (arr[index] == 0)
        {
            count++;
        }
        decrease_count(arr, start, end, index - 1);
    }
    return count;
}

// for getting the sum
int decrease_sum(int *arr, int start, int end, int index)
{
    if (start == index)
    {
        return arr[start];
    }
    sum = sum + arr[index] + decrease_sum(arr, start, end, index - 1);
}
int main()
{
    int *arr = malloc(5 * sizeof(int));
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = -1;
    arr[3] = 9;
    arr[4] = 6;
    decrease_sum(arr, 0, 4, 4);
    printf("%d\n", sum);
    printf("%d", decrease_count(arr, 0, 4, 4));
}