#include <stdio.h>

int *insertion_sort(int *arr, int n)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while(i < n)
    {
        j = i;
        tmp = arr[i];
        while(--j >= 0 && tmp < arr[j])
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
        i++;
    }
    return (arr);
}

int  main()
{
    int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int *sorted;
    int i;

    sorted = insertion_sort(arr, 7);
    i = -1;
    while(++i < 7)
        printf("%d\n", sorted[i]);
    return (0);
}