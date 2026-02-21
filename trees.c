#include<stdio.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* create(int val)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(int val,struct node *root)
{
    if(root==NULL)
    {
        root=create(val);
        return root;
    }
    
    if(root->left==NULL)
    {
        root->left=create(val);
        return root;
    }
    else if ( root->right==NULL)
    {
        root->right=create(val);
        return root;
    }

    insert(val,root->left);

    return root;

}

int main()
{
    int n;
    int parent[n];
    int rel[n];
    int data[n];

    struct node* vals[n];
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        vals[i]=malloc(sizeof(struct node));
        vals[i]->data=data[i];
        vals[i]->left=NULL;
        vals[i]->right=NULL;
    }

    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            root=vals[i];
        }
        else
        {
            if(rel[i]==0)
            {
                vals[parent[i]]->left = vals[i];
            }
            else
            {
                vals[parent[i]]->right=vals[i];
            }
        }

    }


}

void postorder(struct node*root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

void inorder(struct node*root)
{
    if(root=NULL)
    return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root == NULL)
    return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void bfs(struct node* root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (!empty())
    {
        struct node* temp = peek();
        dequeue();

        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int countNodes(struct node * root)
{
    if(root==NULL)
    return 0;

    return 1 + countNodes(root->left) + countNodes(root->right); // basically visit each node and add its left and right children
}

int countLeaf(struct node*root)
{
    if(root == NULL)
    return 0;

    if(root->left == NULL && root->left == NULL)
    {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->left);


}
void mirror(struct node* root)
{
    if (root == NULL)
        return;

    // swap left and right
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}
int height(struct node* root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}
int hi(struct node* root, int* dia)
{
    if (root == NULL)
        return 0;

    int lh = hi(root->left, &dia);
    int rh = hi(root->right, &dia);

    *dia = max(*dia, lh + rh + 1);

    return 1 + max(lh, rh);
}
int diam(struct node* root)
{
    int dia = 0;
    hi(root, &dia);
    return dia;
}

struct node* lca(struct node* root,int p,int q)
{
    if(root == NULL)
    return NULL;

    if(root == p || root == q)
    return root;

    struct node* leftLCA = LCA(root->left, p, q);
    struct node* rightLCA = LCA(root->right, p, q);

    if (leftLCA && rightLCA)
    return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;

}

int pathLen = 0;

bool path(struct node* root, int arr[], int x)
{
    if(root == NULL)
        return false;

    arr[pathLen++] = root->data;

    if(root->data == x)
        return true;

    if(path(root->left, arr, x) || path(root->right, arr, x))
        return true;

    
    pathLen--;
    return false;
}
