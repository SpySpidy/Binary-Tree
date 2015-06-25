#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int value;
    int ht;
    int lvl;
    struct Tree *leftside;
    struct Tree *rightside;
    struct Tree *parentptr;
};
typedef struct Tree tree;
tree *root;
tree *tail;


int insert(int);
int search(int);
//void display(tree *);
int height_set(tree *);
//void display();

int main(int argc, char *argv[])
{
    int flag,choice;
    int value;
    int index;

    while(1)
    {
        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Search \n3. Display\n4. Exit\n");
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
          //  display();
            break;
        case 4:
            return 0;
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
        root->parentptr=NULL;
        root->lvl=0;
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
        child->parentptr=parent;
        child->lvl=child->parentptr->lvl+1;
        if(num <= parent->value)
            parent->leftside=child;
        else
            parent->rightside=child;
            height_set(child);
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
/*void display(tree *ptr)
{
    if (ptr)
    {
        printf("%d\n",ptr->value);
        display(ptr->leftside);
        display(ptr->rightside);
    }
}*/
int height_set(tree *temp)
{
    int lh,rh;
    if(temp==NULL)
        return(0);
    if(temp->leftside==NULL)
        lh=0;
    else
        lh=temp->leftside->ht;
    if(temp->rightside==NULL)
        rh=0;
    else
        rh=temp->rightside->ht;
    if(lh>rh)
    {
        temp->ht=lh+1;
    }
    else
    {
        temp->ht=rh+1;
    }
    height_set(temp->parentptr);
}
/*void display()
{
    int i,j,c=root->ht;
    for(i=0;i<c;i++)
    {

    }
}
*/
