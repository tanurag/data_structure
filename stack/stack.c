/*this program is simple program representing stack*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct _stack{
	int top;
	unsigned capacity;
	int *array;
};

//function to create stack for given capacity
struct _stack* create_stack(unsigned capacity)
{
	struct _stack* stack =(struct _stack*)malloc(sizeof(struct _stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity *sizeof(int));
	return stack;
}

//stack is full when the top is equal to the last index.
int is_full(struct _stack *stack)
{
	return stack->top=stack->capacity-1;
}

int is_empty(struct _stack* stack)
{
	return stack->top==-1;
}

//function to add a item to stack
void push(struct _stack *stack,int item)
{
	if(!is_full(stack))
		return;
	stack->array[++stack->top]=item;
	printf("%d pushed to stack\n",item);
}

int pop(struct _stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}


//peek
int peek(struct _stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top];

}

int main()
{
	struct _stack *stack=create_stack(100);

	push(stack,10);
	push(stack,20);
	push(stack,30);

	printf("%d popped from stack\n",pop(stack));
	printf("Top item is %d\n",peek(stack));

	return 0;
}
