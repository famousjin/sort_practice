#include <stdio.h>

int *bubble_sort(int *arr, int n)
{
    int i;
    int j;
    int m;
    int tmp;

    i = n - 1;
    m = 0;
    while (i > 0)
    {
        j = 0;
        while(j < i)
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i--;
    }
    printf("n time turned : %d\n", m);
    return (arr);
}

int  main()
{
    int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int *sorted;
    int i;

    sorted = bubble_sort(arr, 7);
    i = -1;
    while(++i < 7)
        printf("%d\n", sorted[i]);
    return (0);
}