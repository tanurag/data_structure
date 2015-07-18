/*
 * Dynamic Connectivity
 * Given Set of N objects:
 *	Union Commnads:connect two objects
 *	Find/Connected Query: is there a path connecting the two
 *				objects.
 */

/*****
 * Applications: Digital photo
 *		 Network
 *		 Computer chip
 */

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int objects;

/*
 * This function do the union between two given elements
 */


int union_cmd(int id[],int a,int b)
{
	int i;
	int pid=id[a];
	int qid=id[b];
	for(i=0;i<objects;i++)
	{
		/*
		 * Traverse the array and finds out the all the
		 * items with pid and then changes those values 
		 * to qid so all the elements with same id are
		 * connected
		 */
		if(id[i]==pid)
			id[i]=qid;
	}
}


/*
 * This function finds if the two elements are connected
 */
int is_connected(int id[],int a,int b)
{
	if(id[a]==id[b])
		return TRUE;
	else 
		return FALSE;
}

/*
 * Driver Program
 */


int main()
{

	int id[50];
	int data[10][2];
	int a,b;
	int i;
	printf("Enter the no of objects:\n");
	scanf("%d",&objects);
	for(i=0;i<objects;i++)
		id[i]=i;
	for(i=0;i<objects;i++){
		printf("Enter two elements\n");
		scanf("%d%d",&a,&b);
		if(is_connected(id,a,b))
			printf("Already Connected\n");
		else
			union_cmd(id,a,b);
	}
}

