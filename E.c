#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
	char data;
	struct node *rchild;
}*root=NULL;
struct node *createTree()
{
	char x,y;
	scanf("%c",&x);
	scanf("%c",&y); //  as a buffer
	if(x-48==0)
	{
	  return NULL;
	}
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->lchild=ptr->rchild=NULL;
	printf("Enter the left child of %c\n",ptr->data);
	ptr->lchild=createTree();
	printf("Enter the right child of %c\n",ptr->data);
	ptr->rchild=createTree();
	return ptr;	
}
void preorder(struct node *root)
{
	if(root==NULL)  
	{
		return;
	}
	printf("%c ",root->data);
	preorder(root->lchild);
	preorder(root->rchild);	
}
void Inorder(struct node *root)
{	    
	if(root==NULL)  
	{
		return;
	}
	Inorder(root->lchild);        
	printf("%c ",root->data);        
	Inorder(root->rchild);
}
void postorder(struct node *root)
{
	if(root==NULL)  
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c ",root->data);
	
}
int main()
{
	printf("Enter the data of nodes of the tree (0 for no input)\n");
	printf("Enter the root element\n");
	root=createTree(root);	
	printf("\nThe preorder traversal is\n");
	preorder(root);
	printf("\n\nThe inorder traversal is\n");
	Inorder(root);
	printf("\n\nThe postorder traversal is\n");
	postorder(root);
	return 0;
}