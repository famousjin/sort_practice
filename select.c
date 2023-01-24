#include <stdio.h>

int *selection_sort(int *arr, int n)
{
    int i;
    int j;
    int tmp;
    int index_min;

    i = 0;
    while (i < n)
    {
        index_min = i;
        j = i + 1;
        while(j < n)
        {
            if(arr[j] < arr[index_min])
                index_min = j;
            j++;
        }
        tmp = arr[index_min];
        arr[index_min] = arr[i];
        arr[i] = tmp;
        i++;
    }
    return(arr);
}

int  main()
{
    int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int *sorted;
    int i;

    sorted = selection_sort(arr, 7);
    i = -1;
    while(++i < 7)
        printf("%d\n", sorted[i]);
    return (0);
}