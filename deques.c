#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node*prev;
};
struct node*front=NULL;
struct node*rear=NULL;

void addf(int val)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(front==NULL)
    {
        front =temp;
        rear=temp;
        return;
    }
    temp->next=front;
    front->prev=temp;
    front=temp;


}
void addb(int val)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(rear==NULL)
    {
        rear=temp;
        front=temp;
        return;
    }

    rear->next=temp;
    temp->prev=rear;
    rear=temp;
    

}

void remf()
{
    if(front==NULL || front->next==NULL)
        {front=NULL;
        rear=NULL;
        return;
    }

    struct node *temp = front;
    front=front->next;
    front->prev=NULL;
    free(temp);  
}



void remb()
{
    if(front==NULL || front->next==NULL)
        {front=NULL;
        rear=NULL;
        return;
    }

    struct node *temp =rear;
    rear=rear->prev;
    rear->next=NULL;
    free(temp);

}

bool empty()
{
    if(front==NULL)
    return true;
    else 
    return false;
}
int main()
{
    addf(10);
    addf(30);
    addb(20);
    remf();
    remb();
    remb();
    printf("%d",empty());
  

    while(front!=NULL)
    {
        printf("%d ",front->data);
        front=front->next;
    }

}
