#include <stdio.h>

#define MAX 5

int data[MAX];
int priority[MAX];
int size = -1;

// Insert element
void enqueue(int value, int pr)
{
    if(size == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    size++;
    data[size] = value;
    priority[size] = pr;
}

// Find highest priority index
int peek()
{
    int highest = -1;
    int index = -1;

    for(int i = 0; i <= size; i++)
    {
        if(priority[i] > highest)
        {
            highest = priority[i];
            index = i;
        }
    }

    return index;
}

// Delete highest priority element
void dequeue()
{
    int index = peek();

    if(index == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted element: %d\n", data[index]);

    for(int i = index; i < size; i++)
    {
        data[i] = data[i+1];
        priority[i] = priority[i+1];
    }

    size--;
}

// Display queue
void display()
{
    for(int i = 0; i <= size; i++)
    {
        printf("Element: %d Priority: %d\n", data[i], priority[i]);
    }
}

int main()
{
    enqueue(10,2);
    enqueue(20,5);
    enqueue(30,1);
    enqueue(40,4);

    display();

    dequeue();

    printf("\nAfter deletion\n");
    display();

    return 0;
}