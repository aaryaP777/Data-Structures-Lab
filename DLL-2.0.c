#include<stdio.h>

struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
int main()
{
	struct node*first, *second, *third, *f, *s, *t, *ptr, *head;
	first=(struct node*)malloc(sizeof(struct node));
	first->data=35;
	first->next=NULL;
	first->prev=NULL;
	
	second=(struct node*)malloc(sizeof(struct node));
	second->data=98;
	second->next=NULL;
	second->prev=first;
	first->next=second;
	
	third=(struct node*)malloc(sizeof(struct node));
	third->data=45;
	third->next=NULL;
	third->prev=second;
	second->next=third;
	
	printf("The linked list 1 is:\n");
	ptr=first;
	while(ptr->next!=NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
    
    f=(struct node*)malloc(sizeof(struct node));
	f->data=48;
	f->next=NULL;
	f->prev=NULL;
	
	s=(struct node*)malloc(sizeof(struct node));
	s->data=45;
	s->next=NULL;
	s->prev=f;
	f->next=s;
	
	t=(struct node*)malloc(sizeof(struct node));
	t->data=65;
	t->next=NULL;
	t->prev=s;
	s->next=t;
	
	printf("\nThe linked list 2 is:\n");
	ptr=f;
	while(ptr->next!=NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");

    int c;
    printf("\nEnter 1  to concatenate or 2 to reverse:\n ");
    scanf("%d", &c);
    if(c==1)
    {
    	f->prev=third;
    	third->next=f;
	}
    ptr=first;
	while(ptr->next!=NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
    
    scanf("%d", &c);
    if(c==2)
    {
    	head->next=second;
    	head->prev=NULL;
    	third->prev=NULL;
    	third->next=second;
    	second->prev=third;
    	
    	second->next=first;
    	first->prev=second;
    	first->next=NULL;    	
	}
    ptr=third;
	while(ptr->next!=NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");


	
	
}
