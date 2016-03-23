#include<stdio.h>
#include<stdlib.h>

/* A node for the Linked list*/
struct node {
	int data;
	struct node *next;
};

/*Function to reverse a linked list*/
static void reverse(struct node **root)
{
	struct node *prev=NULL;
	struct node *curr=*root;
	struct node *next=NULL;

	while(curr != NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}

	*root=prev;
}


/*function to recurse link list recursively*/
void recursive_reverse(struct node **root)
{
	/*empty_list*/
	if(*root==NULL)
		return;
	struct node* first=*root;
	struct node* rest=first->next;

	if (rest==NULL)
		return;
	recursive_reverse(&rest);
	first->next->next=first;

	first->next = NULL;

	*root=rest;


}


/*Function to swap nodes in linked list without changing links*/
void swap(struct node** root,int x,int y)
{
	if (x==y)
		return;
	struct node *cur_x = *root;
	struct node *prev_x = NULL;

	while(cur_x && cur_x->data != x){
		prev_x=cur_x;
		cur_x=cur_x->next;

	}
	if (!cur_x )
		return;
	struct node *cur_y=*root;
	struct node *prev_y= NULL;

	while(cur_y && cur_y->data != y){
		prev_y=cur_y;
		cur_y=cur_y->next;
	}

	if (!cur_y)
		return;

	/*Previous pointers setup*/
	if (prev_x !=NULL)
		prev_x->next=cur_y;
	else
		*root=cur_y;
	if(prev_y != NULL)
		prev_y->next=cur_x;
	else
		*root= cur_x;
	/*swap next pointers*/
	struct node *temp=cur_y->next;
	cur_y->next=cur_x->next;
	cur_x->next=temp;


}	



/*add a node at start of the linked list*/
void push(struct node** root,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*root;
	*root=new_node;
}

/*Function to print a linked list*/
void print_list(struct node *node)
{
	struct node *temp=node;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

/*Main function*/
int main()
{

	struct node *root=NULL;
	
	push(&root,10);
	push(&root,20);
	push(&root,30);
	push(&root,40);
	
	swap(&root,10,40);

	printf("Printing the link list\n");
	print_list(root);
	reverse(&root);
	printf("Printing reverse linked list");
	print_list(root);
	recursive_reverse(&root);
	print_list(root);
	return 0;
}
