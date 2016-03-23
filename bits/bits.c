#include<stdio.h>
#include<stdint.h>

/*
 * This function clears the rightmost bit and produces zero if
 * there is no set bit in no.
 * This can be also optimized to check if the integer is power of 2.
 * just by checking the zero and 1
 */

uint8_t clear_rightmost_bit(uint8_t a)
{
	return (a&(a-1));
}

/*
 * This function checks if the given no is of form 2n-1 
 */

uint8_t check_2n_1(uint8_t a)
{
	return (a&(a+1));
}

int main()
{
	uint8_t a=7;
	if(!clear_rightmost_bit(a))
		printf("Power of two");
	else 
		printf("Not power of two.");

	if(check_2n_1(a))
		printf("Not Power of 2n-1\n");
	else
		printf("Power of 2n+1");

	printf("Data %x\n",clear_rightmost_bit(a));
	return 0;

}

