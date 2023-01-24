#include <stdio.h>

//��ġ�� �ٲ��ִ� �Լ�
void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

//�迭�� �����ִ� �Լ�
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
        if(left < right) //left�� pivot���� ũ�� right�� pivot���� ������!
            swap(&arr[left], &arr[right]);  
        //���� ���ٰ� left�� right�� ��ġ�� while���� ��������         
    }
    swap(&arr[right], &arr[pivot]); //�׷��� pivot�� ��ģ ���� �ٲ���

    return(right); // pivot��ġ�� ��ȯ����
}

//�迭�� �����ִ� �Լ�
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
