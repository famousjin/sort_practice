#include <stdio.h>

//위치를 바꿔주는 함수
void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

//배열을 비교해주는 함수
int    quick_sorting(int *arr, int start, int end)
{
    int pivot;
    int left;
    int right;
    int tmp;

    pivot = start;
    left = start;
    right = end + 1;

    while(left < right)
    {
        while(left <= end && arr[left] < arr[pivot])
            left++;
        while(right >= start && arr[right] > arr[pivot])
            right--;
        if(left < right) //left가 pivot보다 크고 right가 pivot보다 작으면!
            swap(&arr[left], &arr[right]);  
        //착착 돌다가 left와 right이 겹치면 while문을 빠져나옴         
    }
    swap(&arr[right], &arr[pivot]); //그러면 pivot과 겹친 곳을 바꿔줌

    return(right); // pivot위치를 반환해줌
}

//배열을 보내주는 함수
void    quick_sort(int *arr, int start, int end)
{
    int pivot;

    if(start < end)
    {
        pivot = quick_sorting(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int i;

    quick_sort(arr, 0, 6);

    i = -1;
    while (++i < 7)
        printf("%d ", arr[i]);
    printf("\n");
    return (0);
}
