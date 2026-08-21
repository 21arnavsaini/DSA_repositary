#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insertNode(struct node *node, int value)
{
    if (node == NULL)
        return createnode(value);
    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    return node;
}
void rsearch(struct node *node, int value)
{
    if (node == NULL)
    {
        printf("Value not found");
        return;
    }
    if (node->data == value)
    {
        printf("%d ", node->data);
        printf("Found");
    }
    else if (value < node->data)
    {
        printf("%d ", node->data);
        rsearch(node->left, value);
    }
    else
    {
        printf("%d ", node->data);
        rsearch(node->right, value);
    }
}
void isearch(struct node *node, int value)
{
    while (node != NULL)
    {
        if (node->data == value)
        {
            printf("Found");
            return;
        }
        else if (value < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    printf("Value not found");
}
int main()
{
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    rsearch(root,0 ); // Search for a value in the BST
    return 0;
}