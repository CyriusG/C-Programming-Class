/* 
 * data_analysis
 *	
 * Calculates the sum for a specific quarter based on user input
 *
 * Joacim Eriksson
 * 2016-04-26
*/
#include <stdio.h>
#include "data_analysis.h"
#define NUMBER_OF_QUARTERS 4
#define NUMBER_OF_SALESMEN 3

int main(void) 
{
    /* Declare and initialize variables */
	float sales[NUMBER_OF_QUARTERS][NUMBER_OF_SALESMEN]=
        {{3.3, 2.2, 7.1}, 
        {4.0, 5.5, 3.1}, 
        {6.9, 0.0, 3.5}, 
        {2.2, 2.2, 1.2}};
	int quarter, headerIndex, salesmenIndex, quarterIndex, running = 1, validMenuInput, quarterInput;

    do
    {
        /* Print all sales for every quarter per salesman in a tabular fashion */
        printf("%11s","Quarter");
        /* Print the number of each quarter */
        for (headerIndex = 0; headerIndex < NUMBER_OF_QUARTERS; ++headerIndex) 
        {
            printf("%5d", headerIndex + 1);

            /* If it is the last quarter print a new line */
            if(headerIndex == NUMBER_OF_QUARTERS - 1)
            {
                printf("\n");
            }
        }

        /* Print the sales figures for the salesman for each quarter */
        for (salesmenIndex = 0; salesmenIndex < NUMBER_OF_SALESMEN; ++salesmenIndex) 
        {
            /* Print what salesman a line belongs to */
            printf("%10s", "Salesman ");
            printf("%d", salesmenIndex + 1);

            /* Print the sales figure for every quarter for that salesman */
            for (quarterIndex = 0; quarterIndex < NUMBER_OF_QUARTERS; ++quarterIndex) 
            {
                printf("%5.1f", sales[quarterIndex][salesmenIndex]);
                /* If it is the last quarter, print also a new line */
                if(quarterIndex == NUMBER_OF_QUARTERS - 1)
                {
                    printf("\n");
                }
            }
        }

        /* Ask the user to input a quarter to sum up */
        do
        {
            /* Print instructions */
            printf("Enter what quarter to calculate the sum off: ");
          
            /* Scan for a quarter and save the number of read values fro error checking */
            quarterInput = scanf("%d", &quarter); 
        }
        /* Loop only if the user input was valid to prevent infinite loop */
        while(quarterInput == 1 && (quarter > NUMBER_OF_QUARTERS || quarter < 1));
         
        if(quarterInput == 1)
        { 
            /* Print the results */
            printf("Sum of quarter %d was %.1f\n", quarter, quarterSum(sales, quarter));

            /* Ask if the user wants to run the program again */
            printf("\nEnter 0 to exit the program or any non-zero, positive number to run again: ");
            validMenuInput = scanf("%d", &running);
          
            /* Exit the program if the user inputs garbage */
            if(running < 0 || validMenuInput < 1)
            {
                running = 0;
            }
        }
        else
        {
            running = 0;
        }
    }
    while(running);

    /* The program ran without any problems */
    return 0;
}

/*
 * Function quarterSum
 * ___________________
 * Sums up the sales for a quarter specified
 *
 * sales[][3]: The sales figure to sum up
 * quarter: What quarter to sum up
 *
 * returns: Returns the sum of the sales figures for the specified quarter or 0 if an invalid 
 *          quarter was inputed
 */
float quarterSum(const float sales[][3], int quarter) 
{
    /* Declare and initialize variables, i used as index for the loop used to sum up the sales */
    int i;
    float sum = 0;
  
    /* Make sure the input is sane */
    if(quarter > 0 && quarter < 5)
    {
        /* Loop through all the salesmen */
        for (i = 0; i < NUMBER_OF_SALESMEN; ++i) 
        {
            /* 
            * The user is asked to input quarter 1 - 4, therefore it is required to subtract 1 
            * from the quarter
            */
            sum += sales[quarter - 1][i];
        }
    }

    /* 
    * Returns the calculated sum, if the user inputed a non-existant quarter (i.e. something that 
    * was not between 1 and 4), it will return a 0 
    */
    return sum;
}
