#include <stdio.h>
#define MAX 5

int Lqueue[MAX];
int front = -1, rear = -1;

void insert(int a)
{
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
    {
        printf("Queue Overflow!\n");
        return;
    }
    else if (front == -1)
    { 
        front = rear = 0;
        Lqueue[rear] = a;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        Lqueue[rear] = a;
    }
    else
    {
        rear++;
        Lqueue[rear] = a;
    }
    printf("%d inserted into the queue.\n", a);
}

int delete()
{
    if (front == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }

    int deleted = Lqueue[front];
    if (front == rear)
    {
        front = rear = -1; 
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return deleted;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", Lqueue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", Lqueue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", Lqueue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice, val, deleted;

    while (1)
    {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &val);
            insert(val);
            break;

        case 2:
            deleted = delete();
            if (deleted != -1)
            {
                printf("Deleted element: %d\n", deleted);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
