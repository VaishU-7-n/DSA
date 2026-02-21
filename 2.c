#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node * front=NULL;
struct node*rear=NULL;

void enqueue(int val)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;

    if(rear==NULL)
    {
        rear=temp;
        front=temp;
        return;
    }
    rear->next =temp;
    rear =temp;

}

void dequeue()
{
    if(front==NULL)
    return;

    if(front->next==NULL)
    {
        front=rear=NULL;
        return;
    }

    struct node*temp = front;
    front=front->next;

    free(temp);
    

}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();

}
