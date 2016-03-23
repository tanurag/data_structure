#include<stdio.h>
#include<string.h>


int main()
{
	char string[1000];
	int len;

	strcpy(string,"blinky");
	len=strlen(string);

	int i;
	int j;

	char temp;

	for(i=0,j=len-1;i<j;i++,j--){
		temp=string[i];
		string[i]=string[j];
		string[j]=temp;
	}

	printf("%s\n",string);
	return 0;
}
