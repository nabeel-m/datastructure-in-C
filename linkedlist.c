#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insertNodeAtBeginning();
void displaylist();

int main()
{
    int n, data;
    printf("Enter the total no. of nodes:");
    scanf("%d",&n);
    createlist(n);

    printf("Data in the list \n");
    displaylist();

    printf("Enter data to insert at beginning:");
    scanf("%d",&data);
    insertNodeAtBeginning(data);

    printf("Enter the data in the list\n");
    displaylist();
    return 0;
}

void createlist(int n)
{
    struct node* newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("unable to allocate to memmory.");
    }
    else
    {
        printf("Enter the data node 1:");
        scanf("%d",&data);

        head->data = data;
        head->next = NULL;

        temp = head;
        for (i=2; i<=n; i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memmory");
                break;
            }
            else
            {
                printf("Enter the data of node %d:",i);
                scanf("%d",&data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;

            }
        }
    printf("SINGLE LINKED LIST CREATED SUCCESSFULY\n");
    }
} 

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode =  (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("unable to allocate memmory");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;
        printf("Data Inserted successfuly\n");
    }
}

void displaylist()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data=%d\n",temp->data);
            temp=temp->next;
        }

    }
}
