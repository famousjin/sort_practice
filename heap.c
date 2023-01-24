#include <stdio.h>
/*
void    heapify(int *arr, int size) //�����¸� ������.
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

    //���� �迭�� ����ϱ� ���� printf
    i = 0;
    printf("Original arr\n");
    while(i < 7)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    
    //heap sort ����
    i = 0;
    size = 7;
    while(i < 7)
    {
        heapify(arr, size); //�����·� ������ְ�
        swap_root(arr, size); //��Ʈ���� ��������带 �ٲ��ش�
        size--; //������ ���� �����ϱ� ���ؼ� ���ڸ� ���̰�
        i++; //���� ���ʷ� �Ѿ��.
    }
	
    //��ȭ �� �迭�� ����ϱ� ���� printf
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

void    heapify(int *arr, int size) //�����¸� �����.
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
            root = (child - 1) / 2; //��Ʈ����� ���̸� ���ϴ� ���
            if(arr[root] < arr[child]) //���࿡ ��Ʈ��尡 �ڽĳ�庸�� �۴ٸ� �ٲ��ֱ�
            {
                tmp = arr[root];
                arr[root] = arr[child];
                arr[child] = tmp;
            }
        child = root; // �ٽ� �������� ���ư���. 
        }
        i++; // i�� �����ϸ鼭 child�� �����Ѵ�.
    }
}

void    swap_root(int *arr, int size) //��Ʈ���� ������ ��� �����ϱ�
{
    int tmp;

    tmp =  arr[0];
    arr[0] = arr[(size - 1)]; //�迭�� 0���� �����ϱ� ������ �ϳ��� �ٿ��ش�.
    arr[(size - 1)] = tmp;
}