/* 
 * creditlimit
 *	
 * Determine if a department store customer has exceeded their credit card limit or not
 * For each customer, their accound number, balance at the beginning of the month, total of all
 * items charged by this customer this month, total of all credits applied to the customer this
 * month and their allowed credit limit.
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	/* Declare variables */
	int AccountNumber;
	float StartBalance, TotalCharged, TotalCredit, AllowedCredit, Balance;
	
	/* Ask the user for an account number and instruct them that -1 ends the prrogram */
	printf("Enter account number (-1 to end): ");
	/* Put that value into the variable 'AccountNumber' */
	scanf("%d", &AccountNumber);

	/* As long as the AccountNumber is not -1, ask for further information and print the results */	
	while(AccountNumber != -1)
	{
		/* Enter the balance at the start of the month */
		printf("Enter start balance: ");
		scanf("%f", &StartBalance);

		/* Enter total charges */
		printf("Enter total charges: ");
		scanf("%f", &TotalCharged);

		/* Enter total credits */
		printf("Enter total credits: ");
		scanf("%f", &TotalCredit);

		/* Enter credit limit */
		printf("Enter credit limit: ");
		scanf("%f", &AllowedCredit);

		/* Print the account number */
		printf("Account: %d\n", AccountNumber);
		/* Print the credit limit */
		printf("Credit limit: %.2f\n", AllowedCredit);
		
		/* Calculate and print the balance */
		Balance = StartBalance + TotalCharged - TotalCredit;
		printf("Balance %.2f\n", Balance);

		/* 
		 * Tell the user they went over their credit limit if the balance is more than the allowed 
		 * credit 
		 */
		if (Balance > AllowedCredit) 
		{
			printf("Credit limit exceeded.\n");
		}
		
		/* Ask the user for an account number and instruct them that -1 ends the prrogram */
		printf("\nEnter account number (-1 to end): ");
		/* Put that value into the variable 'AccountNumber' */
		scanf("%d", &AccountNumber);

	}

	/* Program ran without any problems */
	return 0;
}
