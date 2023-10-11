#include<stdio.h>
#include<stdlib.h>

struct NODE             //define self refrential structure.
{
	int data;
	struct NODE*link;
};

int main()
{
	int c, p;
	struct NODE*head = NULL;  // define temporary pointer to store 1st element.
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->data = 10;
	head->link = NULL; 
	
	struct NODE*secnd = malloc(sizeof(struct NODE));
	secnd->data = 20;
	secnd->link = NULL;
	head->link = secnd;
	
	struct NODE*thrd = malloc(sizeof(struct NODE));
	thrd->data = 30;
	thrd->link = NULL;
	secnd->link = thrd;   
	
	struct NODE*frth = malloc(sizeof(struct NODE));
	frth->data = 40;
	frth->link = NULL;
	thrd->link = frth;   
	
	printf("The linked list is:\n");
	
	struct NODE*ptr = head;	
	while(ptr->link != NULL)
	{
		printf(" %d ->", ptr->data);
		ptr=ptr->link;
	}
	printf(" %d\n", ptr->data);
	
	int ch;
	printf("\n1. Count nodes");               //traversing through the list
	printf("\n2. Add element at the end");    // insert element at end
	printf("\n3. Add element at the begining");
	printf("\n4. Add element at any position");
	printf("\n5. Delete first element");
	printf("\n6. Delete last element");
	printf("\n7. Delete element at any position");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			count_nodes(head);
			break;
			
		case 2:
			printf("Enter element: ");
		    scanf("%d", &c);
			add_end(head, c);
			break;
			
		case 3:
			printf("Enter element: ");
		    scanf("%d", &c);
			add_beg(head, c);
			break;
			
		case 4:
			printf("Enter element: ");
		    scanf("%d", &c);
		    printf("Enter position: ");
		    scanf("%d", &p);
			add_at_pos(head, c, p);
			break;
			
		case 5:
			del_first(head);
			break;
			
		case 6:
			del_last(head);
			break;
			
		case 7:
			del_pos(&head, 4);
			break;				
	}
}

//TRAVERSING
void count_nodes(struct NODE*head)          
{
	int count = 0;
	if(head == NULL)
	{
		printf("List is empty");
	}
	struct NODE*ptr1 = head;
	while(ptr1->link != NULL)
	{
		count++;
		ptr1 = ptr1->link;
	}
	printf(" \nCount is: %d", count);
}

//ADDING ELEMENT AT END
void add_end(head, data)               
{
	struct NODE*ptr2, *temp;
	ptr2 = head;
	temp = malloc(sizeof(struct NODE));
    temp->data = data;
    temp->link = NULL;
    
    while(ptr2->link != NULL)    // check for the last element, then link it to temp to make it last element
    {
    	ptr2 = ptr2->link;
	}
	ptr2->link = temp;
	
	struct NODE*ptr = head;             // to print the new list
	while(ptr->link != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d\n", ptr->data);
		
}

 //ADD NEW ELEMENT AT FRONT  
void add_beg(struct NODE*head, int d)      //this 'head' is local to this func  
{
	struct NODE*ptr3 = malloc(sizeof(struct NODE));  // creat new node
	ptr3->data = d;                                   
	ptr3->link = NULL;              
	
	ptr3->link = head;             //link new node to head of current list
	head = ptr3;                    //put 'head' pointer to new node                
	
	struct NODE*ptr = head;             // to print the new list
	while(ptr->link != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d\n", ptr->data);
		
}

//INSERT ELEMENT AT ANY POSITION
void add_at_pos(struct NODE*head, int data, int pos)
{
	struct NODE*ptR = head;
	struct NODE*ptr4 = malloc(sizeof(struct NODE));
	ptr4->data = data;
	ptr4->link = NULL;
	
	if(pos==2)
	{
		ptr4->link=head->link;
		head->link=ptr4;
	}
	if(pos==3)
	{
		ptr4->link=head->link->link;
		head->link->link=ptr4;
	}
	if(pos==4)
	{
		ptr4->link=head->link->link->link;
		head->link->link->link=ptr4;
	}

	struct NODE*ptr = head;
	while(ptr->link != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d", ptr->data);
}
	

//DELETE FIRST ELEMENT
void del_first(struct NODE*head)
{
	if(head == NULL)
	{
		printf("Empty list !!");
	}
	else
	{	
	    struct NODE*temp = head;    //temp stores add. of first element
	    head = head->link;
	    free(temp);
	    temp = NULL;
    }
    
	struct NODE*ptr = head;
	while(ptr->link != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d", ptr->data);
}

//DELETE LAST ELEMENT
void del_last(struct NODE*head)
{
	if(head == NULL)
	{
		printf("Empty list!!");	
	}
	else if(head->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		struct NODE*temp1=head;     // temp 1 is used to free the memory of separated element
		struct NODE*temp2=head;     // temp 2 used to separate the last element from linked list
		while(temp1->link != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->link;
		}
		temp2->link = NULL;
		free(temp1);
		temp1 = NULL;
	}
	
	struct NODE*ptr = head;
	while(ptr->link != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d", ptr->data);
}

//DELETE ELEMENT AT ANY POSITION
void del_pos(struct NODE**head, int pos)    //double pointer is used because it points to head which is pointing to head of original linked list
{
	struct NODE*cur=*head;
	struct NODE*prev=*head;
	if(*head==NULL)
	{
		printf("Empty list!!!");
	}
	else if(pos==1)
	{
		*head=cur->link;
		free(cur);
		cur=NULL;
	}
	else
	{
		while(pos!=1)
		{
			prev=cur;
			cur=cur->link;
			pos--;
		}
		prev->link=cur->link;
		free(cur);
		cur=NULL;
	}
	
	struct NODE*ptr = *head;
	while(ptr->link != NULL)
	{
		printf(" %d->", ptr->data);
		ptr = ptr->link;
	}
	printf(" %d", ptr->data);
}




