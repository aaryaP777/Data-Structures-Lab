// Double linked list.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*next;
	struct Node*prev;
};

int main()
{
	int ch, c, p;
	struct Node*first=NULL, *f=NULL;                             //1st linked list
	struct Node*second, *third, *s, *t, *ptr, *P1, *P2;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=10;
	first->next=NULL;
	first->prev=NULL;
	
	second=(struct Node*)malloc(sizeof(struct Node));
	second->data=20;
	second->next=NULL;
	second->prev=first;
	first->next=second;
	
	third=(struct Node*)malloc(sizeof(struct Node));
	third->data=30;
	third->next=NULL;
	third->prev=second;
	second->next=third;
	
	f=(struct Node*)malloc(sizeof(struct Node));        //2nd linked list
	f->data=77;
	f->next=NULL;
	f->prev=NULL;
	
	s=(struct Node*)malloc(sizeof(struct Node));
	s->data=88;
	s->next=NULL;
	s->prev=f;
	f->next=s;
	
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=99;
	t->next=NULL;
	t->prev=s;
	s->next=t;

	printf("The linked list is:\n");
	ptr=first;
	while(ptr->next!=NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
    
    printf("1. Add element at beginning.\n");
    printf("2. Add element at end.\n");
    printf("3. Add element at any position.\n");
    printf("4. Delete first element. \n");
    printf("5. Delete element at last.\n");
    printf("6. Delete element at any position.\n");
    printf("7. To Concatenate.\n");
    
    printf("Enter the choice: ");
    scanf("%d", &ch);

switch(ch)
{
	case 1:
		printf("Enter element: ");
		scanf("%d", &c);	
	    add_beg(first, c);
	    break;
	
	case 2:
		printf("Enter element: ");
		scanf("%d", &c);
		add_end(first, c);
		break;
		
	case 3:
		printf("Enter element: ");
		scanf("%d", &c);
		printf("Enter postion: ");
		scanf("%d", &p);
		add_pos(first, c, p);
		break;
		
	case 4:
		del_beg(first);
		break;
		
	case 5:
		del_end(first);
		break;
		
	case 6:
		printf("Enter postion: ");
		scanf("%d", &p);
		del_pos(&first, p);
		break;
		
	case 7:
		printf("The 2nd linked list is:\n");
	    ptr=f;
	    while(ptr->next!=NULL)
	    {
		    printf("%d <-> ", ptr->data);
		    ptr=ptr->next;
        }
        printf("%d\n", ptr->data);
        printf("The concatenated list is:");
        conc(first, f);
		
        
};
}
//ADD AT BEGINNING 
void add_beg(struct Node*first, int data)
{       	
    struct Node*newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->next=first;
	first->prev=newnode;
	first=newnode;
	
	struct Node*ptr=first;
	while(ptr->next!=NULL)
	{
    printf("%d <-> ", ptr->data);
	ptr=ptr->next;
    }  
    printf("%d", ptr->data);
    printf("\n");
}

void add_end(struct Node*first, int data)
{
	struct Node*ptr1=first;
	struct Node*newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	ptr1->next=newnode;
	newnode->prev=ptr1;
	
	struct Node*ptr=first;
	while(ptr->next!=NULL)
	{
    printf("%d <-> ", ptr->data);
	ptr=ptr->next;
    }  
    printf("%d", ptr->data);
    printf("\n");
}

void add_pos(struct Node*first, int data, int pos)
{
	struct Node*newnode=malloc(sizeof(struct Node));   
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	struct Node*temp=first;                            //temp =>position of insertion
	struct Node*temp1=NULL;                            //temp1 =>next position
	
	while(pos != 1)
	{
		temp=temp->next;
		pos--;
	}
	temp1=temp->next;
	temp->next=newnode;
	temp1->prev=newnode;
	newnode->next=temp1;
	newnode->prev=temp;
	
	struct Node*ptr=first;
	while(ptr->next!=NULL)
	{
    printf("%d <-> ", ptr->data);
	ptr=ptr->next;
    }  
    printf("%d", ptr->data);
    printf("\n");	
}

void del_beg(struct Node*first)
{
	struct Node*temp=first;
	first=first->next;
	free(temp);
	temp=NULL;
	
	struct Node*ptr=first;
	while(ptr->next!=NULL)
	{
    printf("%d <-> ", ptr->data);
	ptr=ptr->next;
    }  
    printf("%d", ptr->data);
    printf("\n");
}

void del_end(struct Node*first)
{
	struct Node*temp1=first;
	struct Node*temp2=first;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=NULL;
	free(temp1);
	temp1=NULL;
	
	struct Node*ptr=first;
	while(ptr->next!=NULL)
	{
    printf("%d <-> ", ptr->data);
	ptr=ptr->next;
    }  
    printf("%d", ptr->data);
    printf("\n");
}

void del_pos(struct Node**first, int pos)
{
	struct Node*temp = *first;
	struct Node*temp1 = *first;
    if(pos==1)
	{
		del_beg(*first);
	}
	while(pos>1)
	{
		temp=temp->next;
		pos--;
	}
	if(temp->next == NULL)
	{
		del_end(*first);
	}
	else
	{
		temp1=temp->prev;
		temp1->next=temp->next;
		temp->next->prev=temp1;
		free(temp);
		temp=NULL;
	    struct Node*ptr = *first;
	    while(ptr->next != NULL)
	    {
	     	printf(" %d <->", ptr->data);
		    ptr = ptr->next;
	    }
	    printf(" %d", ptr->data);
    }
}

/*void conc(struct Node*p1, struct Node*p2)
{
	struct Node*ptR, *ptR2=p2;
	for(ptR=p1;ptR->next!=NULL;ptR=ptR->next)
	{
		ptR->next=ptR2;
		ptr2->prev=ptR;
	}
	
	struct Node*ptr=p1;
	while(ptr->next != NULL)
	{
	    printf(" %d <->", ptr->data);
		ptr = ptr->next;
	}
	printf(" %d", ptr->data);
}*/











