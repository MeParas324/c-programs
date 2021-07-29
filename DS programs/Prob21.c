#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *right_child; 
    struct node *left_child; 
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->right_child, x);
    else
        return search(root->left_child,x);
}

struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL)
        return find_minimum(root->left_child);
    return root;
}

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    if(root == NULL)
        return new_node(x);
    else if(x > root->data) 
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);
    return root;
}

struct node* delete(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d  ", root->data);
    }
}

int main()
{
    int choice, element, node_root;
    struct node *root;
    printf("Enter root node: ");
    scanf("%d", &node_root);
    root= new_node(node_root);

    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Add Element");
		printf("\n\t\t 2. Delete Element");
		printf("\n\t\t 3. Inorder display");
		printf("\n\t\t 4. Preorder Display");
        printf("\n\t\t 5. Postorder Display.");
        printf("\n\t\t 6. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to add:");
            scanf("%d", &element);
            insert(root, element);
            break;
        
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            root = delete(root, element);
            break;
        
        case 3:
            inorder (root);
            break;
        
        case 4:
            preorder(root);
            break;
        
        case 5:
            postorder(root);
            break;

        case 6:
            return 0;
            break;

        default:
            printf("Invalid Input.");
            break;
        }
    }
    return 0;
}
