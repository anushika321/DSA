#include<stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value)
{
    int i = size;
    heap[size++] = value;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;

        i = (i-1)/2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(smallest);
    }
}

int deleteMin()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapify(0);

    return root;
}

void display()
{
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);
}

int main()
{
    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(40);

    printf("Min Heap:\n");
    display();

    printf("\nDeleted Min: %d\n", deleteMin());

    printf("Heap after deletion:\n");
    display();

    return 0;
}