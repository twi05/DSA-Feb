#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isFull_queue(struct Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}
bool isEmpty_queue(struct Queue *q)
{
    if (q->rear == q->front)
    {
        q->front = 0;
        q->rear = 0;
        return 1;
    }

    return 0;
}
void enqueue(struct Queue *q, int n)
{
    if (isFull_queue(q))
    {
        printf(" Queue Overflow");
        return;
    }
    q->rear++;
    q->arr[q->rear] = n;
}
int dequeue(struct Queue *q)
{
    if (isEmpty_queue(q))
    {
        printf(" No element to Dequeue");
        return -1;
    }
    int ele = -1;
    q->front++;
    ele = q->arr[q->front];

    return ele;
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 10;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int m[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    int i = 0;
    printf("%d", i);
    enqueue(q, i);
    visited[0] = 1;
    while (!isEmpty_queue(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (m[node][j] == 1 && visited[j] == 0)
            {
                enqueue(q, j);
                printf("%d", j);
                visited[j] = 1;
            }
        }
    }
    return 0;
}