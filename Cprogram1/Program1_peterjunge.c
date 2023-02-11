#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float* file_reader(const char* name)
{
  FILE* inputfile = fopen(name, "r");
  //opens the file
  float* sales = (float*)malloc(sizeof(float)*12);
  //allocates memory for the numbers
  int i = 0;
  for (i=0;i<12;i++){
    fscanf(inputfile,"%f",&sales[i]);
        //reads the numbers and inserts them in corresponding spot of "array"
  }
  fclose(inputfile);
  return sales;
}


void salesread(const char* months[], float* sales){
  int i = 0;
  printf("Monthly sales report for 2022\n");

  printf("Month\tSales\n");
  for(i=0;i<12;i++){
    printf("%-9s\t%8f\n",months[i],sales[i]);
  }
  return;
}

//sales summary
void summary(float* sales, const char* months[])
{
  int i = 0;
  float max = 0;
  float min = sales[0];
  int indexofmax = 0;
  int indexofmin = 0;
  


  for (i=0;i<12;++i){
    if(max <= sales[i]){
      max = sales[i];
      indexofmax = i;
    }
  }
  for (i=0;i<12;++i){
      if (min >= sales[i]){
        min = sales[i];
        indexofmin = i;

      }
    }
  printf("minimum sales: %8f (%s)\n", min, months[indexofmin]);
  printf("maximum sales: %8f (%s)\n", max, months[indexofmax]);

  // average
  float total = 0;
  float average = 0; 
  for (i=0;i<12;i++){
    total += sales[i];
  }
  average = total/12;
  printf("Average Sales: %f\n", average);
}

void sixmonth(float* sales, const char* months[]){
  int i = 0;
  int j = 0;
  float sum = 0;
  float average = 0;
  printf("Six-Month Moving Average Report:\n");
  for (i = 0; i<7;++i){
    sum = 0;
    for (j=i;j<i+6;++j){
      sum += sales[j];
    }
    average = sum/6;
    printf("%-10s\t - \t%-10s\t%-12f\n",months[i],months[j-1],average);
  }

}
void sales_switch(float * a, float * b){
  //bubble sort
  float temp = *a;
  *a = *b; 
  *b = temp;
}
void month_switch(char **a, char **b){
  //bubble sort
  char* temp = *a;
  *a = *b;
  *b =  temp; 
}


void salessort(float* sales, const char* months[]){
  printf("Sales Report (Highest to Lowest)\n");
  printf("  Month\tSales\n");
  float* copysales = (float*)malloc(sizeof(float) * 12);
  
  for (int i=0;i<12;++i){
    copysales[i] = sales[i];
    //copying sales over to copy of sales
  }

  char *monthsorted[12];
  for (int i=0;i<12;++i){
    char* copymonths = (char*)malloc(sizeof(char) * sizeof(months[i]+1));
    strcpy(copymonths, months[i]);
    monthsorted[i] = copymonths;
  }

  for (int i=0;i<12;++i){
    for (int j=0;j<12;++j){
      if (copysales[i]>copysales[j]){
        sales_switch(&copysales[j], &copysales[i]);
        month_switch(&monthsorted[j], &monthsorted[i]); 
      }
    }
  }

  for (int i = 0; i<12;++i){
    printf("%-10s\t%-10f\n", monthsorted[i], copysales[i]);
  }
}

int main(){
  float* sales; 
  const char* months[12] = {"January","Feburary", "March", "April", "May", "June", "July", "August", "September","October", "November", "December"};  
  sales = file_reader("p1input.txt");
  salesread(months, sales);
  summary(sales, months);
  sixmonth(sales,months);
  salessort(sales,months);

  return 0;

}


