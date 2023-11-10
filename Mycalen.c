#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdbool.h>
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int DayOfWeek( int y, int m, int d ) /* returns Day of Week:
0 = Sunday, 1= Monday...
*/
{
 static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
 y -= m < 3;
 return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
} /*--DayOfWeek( )--------*/
// defining macros 
// corners
#define LT 218   //┌
#define RT 191   // ┐
#define LB 192   // └
#define RB 217   // ┘
//  T members
#define TST 194  //  ┬
#define BST 193  //  ┴
#define LST 195  // ├
#define RST 180  //  ┤
// plus
#define PLUS 197  //  ┼
//  Lines and spaces 
#define VL 179    //  │
#define HL 196    // ─ 
#define Space 32   // " "
#define BS 8
// operators
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
// dimensions
#define DIM 7
#define WIDTH 6
#define TOTCOLS 80
#define TOTROWS 25

void drawdabba()
{
  int row;
    int col;
    int ctr1;
    int ctr2;
    int ctr3;
    int ctr4;
    int ctr5;
    col=(TOTCOLS -((WIDTH) * (DIM) + (DIM+1)))/2;
    row=(TOTROWS - (1* (DIM)+(DIM+1)))/2;
    //  FIrst line begins
    gotoxy(col,row);
    printf("%c",LT);
    for(ctr2=0;ctr2<DIM;ctr2++)
    {
    for(ctr1=0;ctr1<WIDTH;ctr1++){
    printf("%c",HL);
    }
    printf("%c",TST);
    }
    printf("%c%c",BS,RT);
   

    // first line nds
   
  //  Printing all lines 

     for(ctr5=0;ctr5<DIM;ctr5++)
     {
       row+=1;
    gotoxy(col,row);
    for(ctr1=0;ctr1<=DIM;ctr1++)
    {
    printf("%c",VL);
     for(ctr2=0;ctr2<WIDTH;ctr2++)
     {
        printf("%c",Space);
     }
    }
    row+=1;
    gotoxy(col,row);
    printf("%c",LST);
    for(ctr3=0;ctr3<DIM;ctr3++)
    {
    for(ctr4=0;ctr4<WIDTH;ctr4++)
    {
    printf("%c",HL);
    }
    
    printf("%c",PLUS);
    }
     printf("%c%c",BS,RST);
     }

    //  LAst line starts:
      gotoxy(col,row);
      printf("%c",LB);
      for(ctr2=0;ctr2<DIM;ctr2++)
      {
      for(ctr1=0;ctr1<WIDTH;ctr1++)
      {
      printf("%c",HL);
      }
      printf("%c",BST);
      }
      printf("%c%c",BS,RB);
    printf("\n\n\n\n\n\n");
}
void colHeadings()
{
  int row;
  int col;
  col=(TOTCOLS -((WIDTH) * (DIM) + (DIM+1)))/2;
    row=(TOTROWS - (1* (DIM)+(DIM+1)))/2;
    
    row+=1;
    col+=2;
    gotoxy(col,row);
    char*days[DIM]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    for(int i=0;i<DIM;i++)
    {
       gotoxy(col+(i*(WIDTH+1)),row);
           printf("%s",days[i]);
         
    }
}
void calender(int month,int year)
{
  int row;
  int col;
 int day_ctr;
    int ctr;
   char *months[]={
   "", "JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"
   };
 
 col=(TOTCOLS -((WIDTH) * (DIM) + (DIM+1)))/2;
    row=(TOTROWS - (1* (DIM)+(DIM+1)))/2;
    //   Printing heading
  gotoxy(30,1);
   printf("%10s , %d", months[month],year);
   row+=3;
    col+=3;
    gotoxy(col,row);
    int days_in_months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    days_in_months[2]=  (((year%4==0) && (year%100!=0))||(year%400==0))? 29:28;
    for(day_ctr=1,ctr=DayOfWeek(year,month,1);day_ctr<=days_in_months[month];day_ctr++,ctr+=1)
    {  if(ctr==DIM)
     {
      
      row+=2;
      ctr=0;
     }

       gotoxy(col+(ctr*(WIDTH+1)),row);
       printf("%02d",day_ctr); 
    }
}
//  clearing calender for every change in month and year to avoid previous month or
void cleancalender()
{
  int col;
  int row;
  int day_ctr;
  int ctr;
  col=(TOTCOLS -((WIDTH) * (DIM) + (DIM+1)))/2;
    row=(TOTROWS - (1* (DIM)+(DIM+1)))/2;
   row+=3;
    col+=3;
    gotoxy(col,row);
    for(day_ctr=1,ctr=0;day_ctr<=42;day_ctr++,ctr+=1)
    {  if(ctr==DIM)
     {
      
      row+=2;
      ctr=0;
     }
       gotoxy(col+(ctr*(WIDTH+1)),row);
       printf("  "); 
    }
printf("\n\nPRESS UP ARROW TO YEAR AHEAD");
   printf("\nPRESS DOWN ARROW TO YEAR BACK");
    printf("\nPRESS RIGHT ARROW TO A MONTH AHEAD");
     printf("\nPRESS LEFT ARROW TO A MONTH BACK");
}
int main()
{
   int month=10; 
   int year=2023;
   int key;
    drawdabba(); 

    colHeadings();
    do{
      cleancalender();
    calender(month,year);

  // Writing operating functions:
  
    getch();
    key=getch();
  
    switch(key)
    {
      case UP:
               year+=1;
               break;
      case DOWN:year-=1;
                 break;
      case LEFT: month-=1;
                 if(month==0)
                 {
                  month=12;
                  year-=1;
                 }
                 break;
      case RIGHT:month+=1;
                 if(month>13)
                 {
                  month=1;
                  year+=1;
                 }
                 
  
    }
    
    }while(key!=ESC);
}