//BINARY SEARCH TREE (recursive)

#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
    int key;
    struct node *left;
	struct node *right;
};
 
struct node* newNode(int item) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)                        //in-order traversal (LDR)
{
    if (root != NULL) 
	{
        inorder(root->left);                // left child
        printf("%d ", root->key);           // root
        inorder(root->right);               // right child
    }
}

void preorder(struct node*root)                    // pre-order traversal (DLR)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node*root)                    // post-order traversal (LRD)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->key);
	}
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node*findMin(struct node*Node)
{
    struct node* current = Node;
    while (current->left != NULL) 
	{
        current = current->left;
    }
    return current;
}

//LEAF NODE DELETION
struct node*del_leaf(struct node*root, int key)
{
    if (root == NULL)
	{
        return root;
    }
   
    else if (key < root->key)
	{
        root->left = del_leaf(root->left, key);
    } 
    
	else if (key > root->key) 
	{
        root->right = del_leaf(root->right, key);
    } 
	
	else 
	{
        if (root->left == NULL && root->right == NULL) 
		{
            free(root);
            root = NULL;
        }
    }
}

//DELETION OF NODE WITH 1 CHILD
struct node*del_node_one(struct node*root, int key)
{
    if (root == NULL)
	{
        return root;
    }
   
    else if (key < root->key)
	{
        root->left = del_node_one(root->left, key);
    } 
    
	else if (key > root->key) 
	{
        root->right = del_node_one(root->right, key);
    } 
	
	else 
	{
        if (root->left == NULL)
		{
			struct node*temp = root->right;
            free(root);
            root = NULL;
        }
        else if (root->right == NULL)
        {
        	struct node*temp = root->left;
        	free(root);
        	root = NULL;
		}
		struct node*temp = findMin(root->right);
        root->key = temp->key;
        root->right = del_node_one(root->right, temp->key);
    }
    return root;   
}

//DELETION OF NODE WITH 2 CHILDREN
struct node*del_node_two(struct node*root, int key)
{
    if (root == NULL)
	{
        return root;
    }
   
    else if (key < root->key)
	{
        root->left = del_node_two(root->left, key);
    } 
    
	else if (key > root->key) 
	{
        root->right = del_node_two(root->right, key);
    } 
	
	else 
	{
        if (root->left == NULL)
		{
			struct node*temp = root->right;
            free(root);
            root = NULL;
        }
        else if (root->right == NULL)
        {
        	struct node*temp = root->left;
        	free(root);
        	root = NULL;
		}
    }
}


int main() 
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");
    /*printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");
    printf("Post-order traversal: ");
    postorder(root);*/
    
    del_node_one(root, 50);
    printf("After deletion");
    printf("\nIn-order traversal: ");
    inorder(root);
 
    return 0;
}
