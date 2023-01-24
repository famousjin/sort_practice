#include <stdio.h>
/*
void    heapify(int *arr, int size) //힙상태를 만들어요.
{
	int i;
    int tmp;
    int root;
    int child;

    i = 1;
    while(i < size)
    {
        child = i;
        while (child != 0)
        {
            printf("first child num : %d\n", child);
            root = (child - 1) / 2;
            printf("first root num : %d\n", root);
			if(arr[root] < arr[child])
            {
				int tmp = arr[root];
				arr[root] = arr[child];
				arr[child] = tmp;
            }
            printf("root node : %d, arr num [%d]\n", arr[root], root);
            printf("child node : %d, arr num [%d]\n", arr[child], child);
            child = root;
            printf("after child = root\n");
            printf("root node : %d, arr num [%d]\n", arr[root], root);
            printf("child node : %d, arr num [%d]\n", arr[child], child);
            printf("\n");
        }
        i++;
    }
}

void    swap_root(int *arr, int size)
{
	int tmp;

    tmp =  arr[0];
	arr[0] = arr[(size - 1)];
	arr[(size - 1)] = tmp;
}

int main()
{	
	int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int size;
    int i;
    int j;

    i = 0;
    size = 7;
	while(i < 7)
    {
		heapify(arr, size);
        j = 0;
        printf("%d time heapify : \n", i);
        while(j < 7)
        {
            printf("%d ", arr[j]);
            j++;
        }
        printf("\n");
		swap_root(arr, size);
        printf("%d time swap_root : \n", i);
        j = 0;
        while(j < 7)
        {
            printf("%d ", arr[j]);
            j++;
        }
        printf("\n");
        printf("size : %d\n", size);
    	printf("\n");
        size--;
        i++;
	}
	
    i = 0;
	while(i < 7)
    {
		printf("%d ", arr[i]);
        i++;
    }
	printf("\n");
	return 0;
}
*/

#include <stdio.h>

void    heapify(int *arr, int size);
void    swap_root(int *arr, int size);

int main()
{	
    int arr[7] = {7, 2, 0, 1, 5, 6, 4};
    int size;
    int i;

    //원래 배열을 출력하기 위한 printf
    i = 0;
    printf("Original arr\n");
    while(i < 7)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    
    //heap sort 시작
    i = 0;
    size = 7;
    while(i < 7)
    {
        heapify(arr, size); //힙상태로 만들어주고
        swap_root(arr, size); //루트노드와 마지막노드를 바꿔준다
        size--; //마지막 노드는 제외하기 위해서 숫자를 줄이고
        i++; //다음 차례로 넘어간다.
    }
	
    //변화 후 배열을 출력하기 위한 printf
    i = 0;
    printf("after heap sort\n");
    while(i < 7)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    return 0;
}

void    heapify(int *arr, int size) //힙상태를 만든다.
{
    int i;
    int tmp;
    int root;
    int child;

    i = 1;
    while(i < size)
    {
        child = i;
        while (child != 0)
        {
            root = (child - 1) / 2; //루트노드의 길이를 구하는 방법
            if(arr[root] < arr[child]) //만약에 루트노드가 자식노드보다 작다면 바꿔주기
            {
                tmp = arr[root];
                arr[root] = arr[child];
                arr[child] = tmp;
            }
        child = root; // 다시 원점으로 돌아간다. 
        }
        i++; // i가 증가하면서 child가 증가한다.
    }
}

void    swap_root(int *arr, int size) //루트노드와 마지막 노드 스왑하기
{
    int tmp;

    tmp =  arr[0];
    arr[0] = arr[(size - 1)]; //배열은 0부터 시작하기 때문에 하나를 줄여준다.
    arr[(size - 1)] = tmp;
}