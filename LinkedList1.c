#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
}*head;


void createList(int n);
void insertNodeAtMiddle(int data, int position);
void displayList();
void insertNodeAtEnd(int data);
void insertNodeAtBeginning(int data);
void deleteFirstNode();
void deleteLastNode();
void deleteMiddleNode(int position);
void deleteList();

int main()
{
	int s,j=2,r;
	int n, data, position;
	do{ 
		printf("\n#####################################################################\n");
		printf("Enter one to create List \n");
		printf("\nEnter two to add item at the begginning \n");
		printf("\nEnter three to add item at the end(last) \n");
		printf("\nEnter four add item at the middle \n");
		printf("\nEnter five to delete item at the begginning \n");
		printf("\nEnter six to delete item at the end(last) \n");
		printf("\nEnter seven delete item at the middle \n");
		printf("\nEnter eight delete all item \n");
		printf("\n#####################################################################\n");
		scanf("%d",&s);
		switch(s)
	    {
		    case 1:
		    	printf("Enter the total number of nodes: ");
			    scanf("%d", &n);
			    createList(n);
			    printf("\nData in the list \n");
	    		displayList();
		   		break;
		    case 2:
		    	printf("\nEnter data to insert at beginning of the list: ");
			    scanf("%d", &data);
			    insertNodeAtBeginning(data);
			    printf("\nData in the list \n");
	    		displayList();
			    break;
		    case 3:
		    	printf("Ensert the data.");
		    	scanf("%d",&data);
		    	insertNodeAtEnd(data);
		    	printf("\nData in the list \n");
	    		displayList();
		    	break;
		    case 4:
		  		printf("nEnter data to insert at middle of the list: ");
			    scanf("%d", &data);
			    printf("Enter the position to insert new node: " );
			    scanf("%d", &position);
			    insertNodeAtMiddle(data, position);
			    printf("\nData in the list \n");
	    		displayList();
		    	break;
		    case 5:
			    deleteFirstNode();
			    printf("\nData in the list \n");
	    		displayList();
			    break;
		    case 6:
			    deleteLastNode();
			    printf("\nData in the list \n");
	    		displayList();
			    break;
		    case 7:
			    printf("\nEnter the node position you want to delete: ");
	    		scanf("%d", &position);
	    		deleteMiddleNode(position);
	    		printf("\nData in the list \n");
	    		displayList();
			    break;
			case 8:
			    deleteList();
			    printf("\nData in the list \n");
	    		displayList();
			    break;
		    default:
		    	printf("no operation for this number");
	    }j = 1;
	printf("\nif you want to continue press num>0 else press 0:");
	scanf("%d",&r);
}while(j<=r);
return 0;
}

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL; 

        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; 

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }

        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}

void deleteList()
{
    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

    printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {

        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode; 
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            newNode->next = temp->next; 
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
            printf("\nData in the list \n");
  			displayList();
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}


void displayList()
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
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                 
        }
    }
}
