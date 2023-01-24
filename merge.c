#include <stdio.h>

void merge(int *arr, int start, int mid, int end)
{
	int sorted[7];
    int sorted_i;
	int i;
	int j;
	
 
    sorted_i = 0;
    i = start;
    j = mid + 1;

	while(i <= mid && j <= end)
	{
		if(arr[i] <= arr[j])
			sorted[sorted_i++] = arr[i++];
		else
			sorted[sorted_i++] = arr[j++];
	}
	while(i <= mid)
		sorted[sorted_i++] = arr[i++];
	while(j <= end)
		sorted[sorted_i++] = arr[j++];
	sorted_i--;
 
	while(sorted_i >= 0)
	{
		arr[start + sorted_i] = sorted[sorted_i];
		sorted_i--;
	}
}

void merge_sort(int *arr, int start, int end)
{
	int mid;

	if(start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main(void)
{
	int arr[7] = { 7, 2, 0, 1, 5, 6, 4 };
	int i;
 
	merge_sort(arr, 0, 6);
 
    i = 0;
    while(i < 7)
        printf("%d\n", arr[i++]);
}
