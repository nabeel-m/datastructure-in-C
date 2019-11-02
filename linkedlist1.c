#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insertNodeAtBeginning();
void insertNodeAtEnd();
void displaylist();
void deleteFirst();
void deleteLast();

int main()
{
    int n, data,choice;
    printf("Enter the total no. of nodes:");
    scanf("%d",&n);
    createlist(n);

    printf("Data in the list \n");
    displaylist();

    printf("choice\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.DELETE FIRST\n4.DELETE LAST\n");
    printf("CHOICE___________:");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Enter data to insert at beginning:");
        scanf("%d",&data);
        insertNodeAtBeginning(data);

        printf("Enter the data in the list\n");
        displaylist();

        return 0;
    }
    if(choice ==2)
    {
        printf("Enter data to insert at end:");
        scanf("%d",&data);
        insertNodeAtEnd(data);

        printf("Enter the data in the list\n");
        displaylist();
        

        return 0;

    } 
    if(choice == 3)
    {
        deleteFirst();

        printf("Enter the data in the list\n");
        displaylist();
        

        return 0;

    }  
    if(choice == 4)
    {
        deleteLast();

        printf("Enter the data in the list\n");
        displaylist();

        return 0;

    } 
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
        printf("Enter the data node:");
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
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;
    newNode=(struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("unable to allocate memmory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        while(temp ->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=newNode;
        printf("Data inserted successfuly.");
    }
    
}

void deleteFirst()
{
    struct node *toDelete;
    if(head == NULL)
    {
        printf("list already empty");
    }
    else
    {
        toDelete = head;
        head=head->next;
        printf("Data deleted=%d\n",toDelete->data);
        free(toDelete);
        printf("Sucessfuly deleted first node from the list");
    }
    
}
void deleteLast()
{
    struct node *todelete, *temp;
    if(head == NULL)
    {
        printf("List node already empty");
    }
    else
    {
        todelete = head;
        temp = head;
        while (todelete->next !=NULL)
        {
            temp = todelete;
            todelete =todelete ->next;
        }
        if(todelete == head)
        {
            head = NULL;

        }
        else
        {
            temp ->next = NULL;

        }
        free(todelete);
        printf("Successfuly deleted last node of the linked list");
        
        

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
