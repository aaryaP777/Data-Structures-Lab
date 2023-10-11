//queue implementation using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*front = NULL;
struct node*rear = NULL;

void enqueue(int value)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    
    if((front==NULL) && (rear==NULL))
    {
        front=rear=ptr;
    }
    
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
    printf("Node is inserted \n");
    
}

int dequeue()
{
    if(front==NULL)
    {
        printf("Underflow");
        return -1;
    }
    
    else
    {
        struct node*temp=front;
        temp->data=front->data;
        front=front->next;
        free(temp);
        return temp->data;
    }
}

void display()
{
    struct node*temp;
    if((front==NULL) && (rear==NULL))
    {
        printf("Empty Queue");
    }
    else{
        printf("The Queue is: \n");
        temp=front;
        while(temp->next!=NULL)
        {
            printf("%d---->", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main()
{
    int choice, value;
    printf("Stack implementation using linked lists\n");
    while(choice!=4)
    {
        printf("1. Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
                
            case 2:
                printf("Popped element is: %d\n", dequeue());
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(4);
                break;
                
            default:
                printf("Wrong choice");
        }
    
    }
    return 0;
}

