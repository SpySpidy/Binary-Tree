#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int value;
    struct Tree *leftside;
    struct Tree *rightside;
};
typedef struct Tree tree;
tree *root;
tree *tail;
int insert(int);
int search(int);
int main(int argc, char *argv[])
{
    int flag,choice;
    int value;
    int index;

    while(1)
    {
        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Search \n3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value you want to insert!\n");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("\nEnter the Number to Search\n");
            scanf("%d",&value);
            flag = search(value);
            if (flag)
            {
                printf("Value found in tree\n");
            }
            else
            {
                printf("Value not found\n");
            }
            break;
        case 3:
            return 0;
            break;
        }
    }
}

int insert(int num)
{
    tree *child, *parent;

    if (root==NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->value=num;
        root->leftside=NULL;
        root->rightside=NULL;
    }
    else
    {
        child=root;
        while (child!=NULL)
        {
            if (num<=child->value)
            {
                parent=child;
                child=child->leftside;
            }
            else
            {
                parent=child;
                child=child->rightside;

            }
        }
        child=(tree *)malloc(sizeof(tree));
        child->value=num;
        child->leftside=NULL;
        child->rightside=NULL;
        if(num <= parent->value)
            parent->leftside=child;
        else
            parent->rightside=child;
    }
}

int search(int value)
{
    tree *temp;
    int c=0;
    temp=root;
    while(temp!=NULL)
    {

        if(value<temp->value)
        {
            temp=temp->leftside;
        }
        else if(value>temp->value)
        {
            temp=temp->rightside;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
