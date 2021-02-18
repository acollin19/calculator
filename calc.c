#include <stdio.h>

/*
 Program to implement a scientific calculator
 ****************************************************************
 *  Author        Dept .          Date          Notes 
 ****************************************************************
 * Angele P   Comp. Science .  Oct 30 2020  Initial version .
 * Angele P   Comp. Science .  Nov 03 2020  Completed Q1-Q7 .
 * Angele P   Comp. Science .  Nov 05 2020  Final Version .
*/

int main (int argc, char *argv[])
{
	int nums1;
	int nums2;
	int longer;
	int i;
	int carry = 0;
        char operand1;
        char operand2;
        int mySum;
        int tmp;
        int out[1002];
	int j;
        int main;
        int started=0;

	// If number of arguments is not 3 and the actual file; so 4
	if (argc != 4)
	{
		printf("Error: invalid number of arguments!\n");
		printf("scalc <operand1> <operator> <operand2>\n");
		return 1;
	}

	// Iterating through the string and checking if the operands are positive integers
	for (nums1=0; nums1 < 1002 ; nums1++ )
       	{
		if ((argv[1])[nums1] == '\0')
		{ // If null then stop
			break;
		}
		
		else if(! ((argv[1])[nums1] >= '0'  && (argv[1])[nums1] <= '9' ))
		{
			printf("Error!! Operand can only be positive integers\n");
			return 1;
			break;
		}
	}
	// Reapeat loop for 2nd operand
	for (nums2=0; nums2 < 1002 ; nums2++ )
        {
                if ((argv[3])[nums2] == '\0')
		{ 
                        break;
                }
                else if(! ((argv[3])[nums2] >= '0'  && (argv[3])[nums2] <= '9' ))
		{ // if between 0  and 9 then counter     
                        printf("Error!! Operand can only be positive integers\n");
                        return 1;
                        break;
                }
        }
	// Check if operator is a +
	if (*argv[2] != '+')
	{
		printf("Error: operator can only be + !\n");
		return 1;
	}

	// Check which operand is longer	
	if(nums1>nums2)
	{
		longer = nums1;
	}	
	else
	{
		longer = nums2;
	}
	
	for (i=1; i<=longer; i++)
	{// Turning ASCII values to ints
		operand1=(argv[1])[nums1-i];
		operand1=operand1-48;
		operand2=(argv[3])[nums2-i];
		operand2=operand2-48;
		
		if(nums1-i<0)
		{
			mySum=operand2+carry;
		}
		else if(nums2-i<0)
		{
			mySum=operand1+carry;
		}
		else
		{
			mySum=operand1+operand2+carry;
		}
		// If sum adds up greater than 9 then carry over	
		if (mySum>9)
		{
			tmp=mySum-10;
			carry=1;
			out[i-1]=tmp;
		}
		else
		{
			carry=0;
			out[i-1]=mySum;
		
		}

	}

	if (carry==1)
	{
		out[i-1]='1'-48;
	}	

	if (*argv[1] == '0' && *argv[3] == '0')
        {
                printf("%d",0);
        }

	// Remove extra characters in front of sums
	for (j=longer; j>=0; j--)
	{
		main = out[j];
		if (!(started==0 && main == 0))
		{
			printf("%d",main);
			started=1;
			
		}
	}

	printf("\n");
}


