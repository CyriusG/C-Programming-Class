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
	float sales[NUMBER_OF_QUARTERS][NUMBER_OF_SALESMEN]=
    {{3.3, 2.2, 7.1}, 
    {4.0, 5.5, 3.1}, 
    {6.9, 0.0, 3.5}, 
    {2.2, 2.2, 1.2}};
	int quarter, headerIndex, salesmenIndex, quarterIndex;
  
  printf("%10s","Quarter");
  for (headerIndex = 0; headerIndex < NUMBER_OF_QUARTERS; ++headerIndex) {
    printf("%5d", headerIndex + 1);

    if(headerIndex == NUMBER_OF_QUARTERS - 1)
    {
      printf("\n");
    }
  }

  for (salesmenIndex = 0; salesmenIndex < NUMBER_OF_SALESMEN; ++salesmenIndex) {

    printf("%10s", "Salesman ");
    printf("%d", salesmenIndex + 1);

    for (quarterIndex = 0; quarterIndex < NUMBER_OF_QUARTERS; ++quarterIndex) {
      printf("%5.1f", sales[quarterIndex][salesmenIndex]);
      if(quarterIndex == NUMBER_OF_QUARTERS - 1)
      {
        printf("\n");
      }
    }
  }

	printf("Enter what quarter to calculate the sum off: ");
	scanf("%d", &quarter);  
  
  printf("Sum of quarter %d was %.1f\n", quarter, quarterSum(sales, quarter));

	return 0;
}

float quarterSum(float sales[][3], int quarter) 
{
  int i;
  float sum = 0;
  
  if(quarter > 0 && quarter < 5)
  {
    for (i = 0; i < NUMBER_OF_SALESMEN; ++i) {
      sum += sales[quarter - 1][i];
    }
  }

  return sum;
}
