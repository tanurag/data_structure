/*
 * This file explains the bit manipulation routines 
 * necessary for doing some little bit of embedded 
 * programming.
 */

/*
 * setting a bit
 * And clearing a bit 
 * Toggleing a bit
 * Method 1 bit masking
 */


/*
 * var|=MASK;
 * var&=MASK;
 * var^=MASK;
 */

#define MASK 0x10
#define SET_BIT1(x) (x|MASK)
#define CLEAR_BIT1(x) (x&MASK)
#define TOGGLE_BIT(x) (x^MASK)


/*
 * checking a bit
 */


