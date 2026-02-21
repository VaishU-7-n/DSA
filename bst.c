#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};



struct node* search(struct node*root,int x)
{   if(root==NULL)
    return NULL;

    if(root->data==x)
    return root;
    else if(root->data < x)
    return search(root->right,x);
    else
    return search(root->left,x);
}

int ceils(struct node*root,int x)
{   int ceil =-1;

    while(root)
    {
        if(root->data==x)
        {
             ceil= root->data;
             return ceil;
        }
       
        if(root->data<x)
        root= root->right;

        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}

int floor(struct node* root,int x)
{   int floo=-1;
    while(root)
    {if(root->data == x)
        {
            floo=root->data;
            return floo;
        }

        if(root->data>x)
        {
            root =root->left;
        }
        else
        {
            floo = root->data;
            root=root->right;

        }
    }

    return floo;
}
struct node* insert(struct node* root,int x)
{
    if(root==NULL)
    {
        struct node* temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }

    if(x < root->data)
        root->left=insert(root->left,x);

    else if(x > root->data)
        root->right=insert(root->right,x);

    return root;
}


struct node* minValueNode(struct node* root)
{
    while(root->left!=NULL)
        root=root->left;

    return root;
}

struct node* delete(struct node* root,int x)
{
    if(root==NULL)
        return root;

    if(x < root->data)
        root->left=delete(root->left,x);

    else if(x > root->data)
        root->right=delete(root->right,x);

    else
    {
        // Case 1 & 2

        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }

        // Case 3

        struct node* temp=minValueNode(root->right);

        root->data=temp->data;

        root->right=delete(root->right,temp->data);
    }

    return root;
}

struct node* LCA(struct node* root,int x,int y)
{
    if(root==NULL)
        return NULL;

    if(x < root->data && y < root->data)
        return LCA(root->left,x,y);

    if(x > root->data && y > root->data)
        return LCA(root->right,x,y);

    return root;
}
