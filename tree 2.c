//   BINARY TREE

#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree*left;
	struct tree*right;
};

struct tree* newnode(int data)
{
	struct tree*node;
	node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void preorder(struct tree*root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct tree*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void inorder(struct tree*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int main()
{
	int root, nd1, nd2, nd3, nd4, nd5;
	printf("Enter the root: ");
	scanf("%d", &root);	
	printf("Enter the node 1: ");
	scanf("%d", &nd1);
	printf("Enter the node 2: ");
	scanf("%d", &nd2);
	printf("Enter the node 3: ");
	scanf("%d", &nd3);
	printf("Enter the node 4: ");
	scanf("%d", &nd4);
	printf("Enter the node 5: ");
	scanf("%d", &nd5);
		
	struct tree*rt=newnode(root);              
	struct tree*n1=newnode(nd1);             
	struct tree*n2=newnode(nd2);
	struct tree*n3=newnode(nd3);
	struct tree*n4=newnode(nd4);
	struct tree*n5=newnode(nd5);
		
	rt->left=n1;
	rt->right=n2;
	n1->left=n3;
	n1->right=n4;
	n2->right=n5;
	
	printf("\npreorder traversal: ");
	preorder(rt);
	printf("\n");
	
	printf("\npostorder traversal: ");
	postorder(rt);
	printf("\n");
	
	printf("\ninorder traversal: ");
	inorder(rt);
	return 0;
}
