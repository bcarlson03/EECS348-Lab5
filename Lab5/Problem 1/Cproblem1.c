#include <stdio.h>


//A bubble sort function will be used to sort the sales numbers.
//In addition to the numbers being sorted, the array of months will also be passed in, so the months will also get "sorted" in line with their sales numbers.
//This makes it so the sales numbers still allign with the proper month at the same index.
//So if August has the second lowest month in sales, both August and the sales number will be at index 1.
int bubbleSort(double array1[], char *array2[], int n)
    {
        for(int i = 0; i < n - 1; i++)
            {
                for(int j = 0; j < n - i - 1; j++)
                    {
                        if(array1[j] > array1[j + 1])
                            {
                                double temp1 = array1[j];
                                char *temp2 = array2[j];
                                array1[j] = array1[j + 1];
                                array2[j] = array2[j + 1];
                                array1[j + 1] = temp1;
                                array2[j + 1] = temp2;
                            }
                    }
            }
        return 0;
    }

int main()
{
    //Opens the sales.txt file in read mode. 
    FILE *file = fopen("sales.txt", "r");

    //Initializes an array of 12 doubles. These will represent the sales amount for each of the 12 months in order from Jan -> Dec.
    double sales[12];

    //For loop that reads each line in the sales.txt file and stores it in an array as a double. 
    for(int i = 0; i < 12; i++)
        {
            if (fscanf(file, "%lf", &sales[i]));
        }

    //Initializes an array containing the 12 months of the year, so they can easily be accessed and printed.
    //The months all need to be the same length so that way they are properly alligned when printed. So the months have extra spaces in the names to make up for it.
    char *months[] = 
        {"January  ", "February ", "March    ", "April    ", "May      ", "June     ",
         "July     ", "August   ", "September", "October  ", "November ", "December "
        };
    
    //The top of the report needs to read "Monthley sales report for 2022:" So i print it."
    printf(" Monthly sales report for 2022:\n\n");
    //The report needs to print the headers "Month", and "Sales", and the the 12 months and their corresponding sales numbers.
    printf(" Month          Sales\n\n");

    for(int i = 0; i < 12; i++)
        {
            printf(" %s      $%.2lf\n", months[i], sales[i]);
        }

    //Skips a line between this section and the next section of the report.
    printf("\n");

    //Then, the program needs to be able to print a "Sales Summary", by printing the minimum and maximum sales and their corresponing months.
    //To evaluate this, four variables are made. These are used to keep track of what number month the maximum and minimum sales belong to, and what those values were.
    double minSales = 100000000.0;
    double maxSales = 0.0;
    int minSalesMonth = 1;
    int maxSalesMonth = 1;

    //This for loop will go through all 12 sales numbers and see if they are the minimum or maximum number. If they are it updates the number and the month number accordingly.
    for(int i = 0; i < 12; i++)
        {
            if(sales[i] > maxSales)
                {
                    maxSales = sales[i];
                    maxSalesMonth = i;
                }
            if(sales[i] < minSales)
                {
                    minSales = sales[i];
                    minSalesMonth = i;
                }
        }

    //Now that it has the maximum and minimum sales, and their months, the program needs to print the corresponding values.
    printf(" Sales Summary:\n\n");
    printf(" Minimum sales: $%.2lf | %s\n", minSales, months[minSalesMonth]);
    printf(" Maximum sales: $%.2lf | %s\n", maxSales, months[maxSalesMonth]);
    
    //To print the average sales, we need to find the average among all 12 months.
    //This can be done with a for loop that iterates through all the values adding them together and then divides by 12.
    double total = 0.0;
    for(int i = 0; i < 12; i++)
        {
            total += sales[i];
        }
    double totalAverage = total / 12;
    printf(" Average sales: $%.2lf\n", totalAverage);

    //Next, I need to print the 6 month moving averages. To do this I will use a for loop that iterates 6 times. Each time it will take the average of a group of 6 months.
    //These averages will be stored in a new array.
    double sixMonthAverages[7];

    //Skip a line before going to the next section.
    printf("\n");

    //Print the section header.
    printf(" Six-Month Moving Average Report:\n\n");

    //Calculate the averages and print the them with their corresponding months.
    for(int i = 0; i <7; i++)
        {
            double avg = ((sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5]) / 6);
            sixMonthAverages[i] = avg;
            printf(" %s - %s $%.2lf\n", months[i], months[i+5], avg+0.001);
        } 
    
    //Skip a line before going to the last section of the report.
    printf("\n");

    //The last section of the report asks for the amounts (with months) to be printed from highest to lowest.
    //Print the section header.
    printf(" Sales Report (Highest to Lowest):\n\n");
    printf(" Month     Sales\n\n");
    bubbleSort(sales, months, 12);
    for(int i = 11; i > -1; i--)
        {
            printf(" %s $%.2lf\n", months[i], sales[i]);
        }
    return 0;
}



