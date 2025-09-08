#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* createnode(int value)
{
	struct node* newnode = ( struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
//inorder traversal(left ? root ? right )
void inorder(struct node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
//preorder traversal(root ? left ? right)
void preorder(struct node* root)
{
	if(root != NULL)
	{
		preorder(root->data);
		printf("%d",root->left);
		preorder(root->right);
	}
}
//postorder traversal (left ? right ? root)
void postorder(struct node* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		printf("%d",root->right);
		postorder(root->data);
	}
}

int main()
{
	struct node* root = createnode(4);
	root->left = createnode(2);
	root->right = createnode(6);
	root->left->left = createnode(1);
	root->left->right = createnode(3);
	root->right->left = createnode(5);
	root->right->left = createnode(7);
	
	printf("Inorder traversal: ");
	inorder(root);
	printf("\n");
	
	printf("preorder traversal: ");
	preorder(root);
	printf("\n");
	
	printf("postorder traversal: ");
    postorder(root);
	printf("\n");
	
}









