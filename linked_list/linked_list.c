/****************************************************
 * Filename: linked_list.c
 * This file's contents are available at geeksforgeeks.com 
 * and for now this is the basic repository in future i will be
 * making it more usable more like linux kernels linked list.
 * *********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/******************************************************
 *          NODE STRUCTURE   
 ******************************************************/

//a node representing a linked list
struct node {
	int data;
	struct node *next;
};

/******************************************************
 *          Insertion
 ******************************************************/

//this function adds a node at start
void push(struct node** head_ref,int new_data)
{
	//allocate node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	//put om the data
	new_node->data = new_data;
	//make next of the new node as head
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

//this function adds a node after a given node
void insert_after(struct node* prev_node,int new_data)
{
	if(prev_node == NULL){
		printf("The given previous node can not be null\n");
		return;
	}

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next=prev_node->next;
	prev_node->next = new_node;
}

//This function adds a node at the end
void append(struct node** head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	struct node* last =*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref == NULL)
	{
		*head_ref=new_node;
		return;
	}
	while(last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

/**********************************************************
 *             Deletion 
 *********************************************************/

//This function deletes a given node
void delete_node(struct node** head_ref,int key)
{
	struct node* temp = *head_ref,*prev;
	
	if(temp != NULL && temp->data==key){
		*head_ref = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
		return;
	
	prev->next = temp->next;
	free(temp);
}

/******************************************************************
 * 		Traversal
 *****************************************************************/

//this function prints contents of linked list starting from the
//given node

void printList(struct node *n)
{
	while(n != NULL)
	{
		printf(" %d ",n->data);
		n=n->next;
	}

}

//this function prints the middle node of the linked list
void print_middle(struct node *head)
{
	struct node *slow_ptr=head;
	struct node *fast_ptr=head;

	if(head != NULL)
	{
		while(fast_ptr !=NULL && fast_ptr->next != NULL)
		{
			fast_ptr=fast_ptr->next->next;
			slow_ptr=slow_ptr->next;
		}
		printf("the middle element is [%d] \n\n",slow_ptr->data);
	}
}


/*****************************************************************
 * 		Count ]
 *****************************************************************/

//Gets the no of elements in linked list
int get_count(struct node* head)
{
	int count =0;
	struct node* current = head;
	while(current != NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}


//Recursively counting the elements in a linked list
int get_count_r(struct node* head)
{
	if(head==NULL)
		return 0;
	return 1+get_count_r(head->next);
}

/*****************************************************
 *                  Searching 
 *****************************************************/
 int search(struct node* head,int x)
 {
 	struct node* current=head;
	while(current != NULL)
	{
		if(current->data==x)
			return 1;
		current=current->next;
	}
	return 0;
}

int search_r(struct node* head,int x)
{
	if(head==NULL)
		return 0;
	if(head->data= x)
		return 1;
	return search_r(head->next,x);
}

/******************************************************
 *   		Nth Node
 ******************************************************/
 int getnth(struct node* head,int index)
 {
 	struct node* current=head;
	int count=0;

	while(current != NULL)
	{
		if(count == index)
			return(current->data);
		else
			count++;

		current=current->next;
	}
	assert(0);
 }

/*******************************************************
 *         Driver
 ******************************************************/

//Program to create simple linked list with three programs
int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	 head=(struct node*)malloc(sizeof(struct node));
	 second=(struct node*)malloc(sizeof(struct node));
	 third=(struct node*)malloc(sizeof(struct node));

	 head->data=1;
	 head->next=second;
	 
	 second->data=2;
	 second->next=third;

	 third->data=3;
	 third->next=NULL;
	
	 append(&head,6);
	 push(&head,5);
	 insert_after(third,4);

	 if(search(head,1))
	 	printf("Item Found \n");
	 printf("Count:%d\n",get_count(head));
	 
	 print_middle(head);
	 printList(head);
	 delete_node(&head,5);
	 delete_node(&head,4);
	 if(!search(head,5))
	 	printf("Item Not Found \n");

	 printf("Count:%d\n",get_count_r(head));
	 printList(head);
	 printf("Data:%d",getnth(head,4));
	 printf("Data:%d",getnth(head,6));
	 return 0;
}

/*********************************End***************************/
