#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int SIZE=4;
    int temp1;
    int temp2;
    int add;
    // rand alone prints same values for one code use srand()
    // numbers from 20 30 ?
    // (rand() %(upperlimit-lowerlimit)+lowerlimit
    // how to get the random digit in to the 2only 2 and 4;
    for(int i=0;i<30;i++)

{    srand(time(NULL));
    temp1=rand()%SIZE;

    srand(time(NULL)+1);
    temp2=rand()%SIZE;
     if(temp1+temp2%2==0)
     {
        
     }
     else{
        add=4;
     }
  printf("%d",add);
}
}