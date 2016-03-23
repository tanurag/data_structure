#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node* new_node(int data)
{
	//allocate memory for new node.
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->data = data;

	//initialize the left and right children as null
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d-->",root->data);
		inorder(root->right);
	}
	printf("\n");
}

struct node* insert(struct node* node,int data)
{
	if (node == NULL) 
		return new_node(data);
	if(data <node->data)
		node->left = insert(node->left,data);
	else if (data >node->data)
		node->right=insert(node->right,data);
	return node;
}

struct node* search(struct node* root,int data)
{
	if(root==NULL || root->data == data)
		return root;
	if(root->data <data)
		return search(root->right,data);
	return search(root->left,data);
}

struct node* minValueNode(struct node* node)
{
	struct node *current =node;
	while(current->left != NULL)
		current = current->left;
	return current;
}


int minValue(struct node* node)
{
	struct node* current = node;
	while(current->left != NULL){
		current = current ->left;
	}
	return current->data;
}
struct node* delete(struct node* root,int data)
{
	if (root == NULL)
		return root;
	if( data <root->data)
		root->left = delete(root->left,data);
	else if(data >root->data)
		root->right=delete(root->right,data);
	else{
		if(root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node *temp=minValueNode(root->right);
		root->data=temp->data;

		root->right = delete(root->right,temp->data);
	}
	return root;
}


int main()
{
	/*create root*/
	struct node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);

	inorder(root);
	
	if(search(root,1000))
		printf("Item found\n");
	printf("Minimum Value :%d\n",minValue(root));
	return 0;
}
