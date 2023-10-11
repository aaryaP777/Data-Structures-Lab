//concatenation, union, intersection of single linked list

#include<stdio.h>
#include<stdlib.h>

struct node                      //structure for linked list 1
{
	int data;
	struct node*link;
};

struct node1                     //structure for linked list 2
{
	int data1;
	struct node1*link1;
};

int main()
{
	struct node*head, *secnd, *thrd, *ptr, *ptR, *ptr3;           
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->link = NULL; 
	
	secnd = (struct node*)malloc(sizeof(struct node));
	secnd->data = 2;
	secnd->link = NULL;
	head->link = secnd;
	
	thrd = (struct node*)malloc(sizeof(struct node));
	thrd->data = 3;
	thrd->link = NULL;
	secnd->link = thrd;   
		
	printf("Linked list 1 is:\t");
	ptr=head;
	while(ptr->link!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->link;
	}
	printf("%d", ptr->data);
	
	struct node1*f, *s, *t, *ptr1;
	f = (struct node1*)malloc(sizeof(struct node1));
	f->data1 = 9;
	f->link1 = NULL;
	
	s = (struct node1*)malloc(sizeof(struct node1));
	s->data1 = 3;
	s->link1 = NULL;
	f->link1 = s;
	
	t = (struct node1*)malloc(sizeof(struct node1));
	t->data1 = 1;
	t->link1 = NULL;
	s->link1 = t;
	
    struct node*result=NULL;
	
	printf("\nLinked list 2 is:\t");
	
	ptr1=f;
	while(ptr1->link1 != NULL)
	{
		printf("%d->", ptr1->data1);
		ptr1=ptr1->link1;
	}
	printf("%d\n", ptr1->data1);
		
	int c;
	printf("1. Concatenate\n2. Reverse\n3. Union\n4. Intersection\n");
	printf("Enter the choice: ");
	scanf("%d", &c);
	
	switch(c)
	{
		case 1:
			thrd->link=f;
			struct node*ptr2=malloc(sizeof(struct node));
			ptr2=head;
			while(ptr2->link != NULL)
			{
				printf("%d->", ptr2->data);
				ptr2=ptr2->link;
			}
			printf("%d", ptr2->data);
			break;
			
		case 2:
			ptr3=malloc(sizeof(struct node));
			ptr3->link=head;                    //ptr3 is temporary pointer
			head=thrd;
			head->link=secnd;
			secnd->link=ptr3->link;
			ptr3->link->link=NULL;
			
			ptR=(struct node*)malloc(sizeof(struct node));
			ptR=head;
			while(ptR->link != NULL)
			{
				printf("%d->", ptR->data);
				ptR=ptR->link;
			}
			printf("%d", ptR->data);
			break;
						
		case 4:
			getintersection(head, f, &result);
			break;
						
	}
}

void getintersection(struct node* head, struct node1* f, struct node**result) {
    struct node* current1 = head;
                                        // Iterate through list1
    while (current1 != NULL) 
	{
        int d1 = current1->data;
        
        struct node1* current2 = f;
        int found = 0;
                                         // Iterate through list2 to check if data1 is present
        while (current2 != NULL) 
		{
            int d2 = current2->data1;
            if (d1 == d2) 
			{
                found = 1;
                break;
            }
            current2 = current2->link1;
        }

        // If data1 is found in list2, add it to the result list
        if (found) {
            struct node* newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = d1;
            newNode->link = *result;
            *result = newNode;
        }
        current1 = current1->link;
    }
    printf("The intersection of the two lists is: ");
    struct node*ptr=*result;
	while(ptr->link!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->link;
	}
	printf("%d", ptr->data);


}




