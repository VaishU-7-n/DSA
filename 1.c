#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node*next;
};
struct node* top =NULL;
bool empty()
{
    if(top == NULL)
    return true;
    else
    return false;
}

int peek()
{
    if(empty()==true)
    {
        return -1;
    }
    return top->data;
}
void push(int x)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data =x;

    if(top == NULL)
    {
        top =temp;
        return;
    }
    temp->next =top;
    top = temp;
}
int pop()
{
    struct node* temp=malloc(sizeof(struct node));
    if(empty()==true)
    {
        return -1;
    }
    temp =top;
    int c = temp->data;
    top =temp->next;
    free(temp);
    return c;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],res[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        res[i]=-1;

    }
    
    int idx=0;
    for(int i=0;i<n;i++)
    {
        while(!empty() && arr[i]>arr[peek()])
        {
            int idx =pop();
            res[idx]=arr[i];
        }
        push(i);

    }

    for(int i=0;i<n;i++)
    printf("%d ",res[i]);
}
