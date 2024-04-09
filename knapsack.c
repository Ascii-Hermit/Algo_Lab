#include <stdio.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}
int knapsack(int capa, int *val, int *weight, int num)
{
    if (capa == 0 || num == 0)
    {
        return 0;
    }
    if (weight[num - 1] > capa)
    {
        return knapsack(capa, val, weight, num - 1);
    }
    else
    {
        return max(val[num - 1] + knapsack(capa - weight[num - 1], val, weight, num - 1), knapsack(capa, val, weight, num - 1));
    }
}

int main()
{
    int val[] = {60, 100, 120}; // values of items
    int wt[] = {10, 20, 30};    // weights of items
    int W = 50;                 // knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value that can be obtained: %d\n", knapsack(W, val, wt, n));
}