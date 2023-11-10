/*
simple calender: 2 switch cases
1st switch case returns the starting day and no.of days of the month selected
2nd switch case prints the 1st date value of the month;
*/
import java.util.*;
class MYcalender{  // "CLASS starts here"
public static void main(String args[])  // "MAIN method starts here"
{
Scanner kb=new Scanner(System.in);
int  a=0;
int b=0;
int m;
int i=1;
int h;
int check=0;
System.out.println("\n Enter the month to print:"); 
m=kb.nextInt();

switch(m)
{
case 1:a= 1;
           b=31 ;
break;
case 2:a= 4;
           b= 28;
break;
case 3:a=4 ;
           b= 31;
break;
case 4:a= 7;
           b= 30;
break;
case 5:a= 2;
           b= 31;
break;
case 6:a=5 ;
           b=30 ;
break;
case 7:a= 1;
           b= 31;
break;
case 8:a= 3;
           b= 31;
break;
case 9:a=6 ;
           b=30 ;
break;
case 10:a= 1;
           b= 31;
break;
case 11:a= 4;
           b= 30;
break;
case 12:a=6 ;
           b= 31;
           break;
default:System.out.println("\n INVALID MONTH");
}
if(m<=12)
{
System.out.printf("\t\t\t%d -Month-2023",m);
System.out.println("\n");
System.out.println("\tsun\tmon\ttue\twed\tthu\tfri\tsat");
switch(a)
{
  case 1: System.out.printf("\t%d",i);
              break;
case 2: System.out.printf("\t\t%d",i);
              break;
case 3: System.out.printf("\t\t\t%d",i);
              break;
case 4: System.out.printf("\t\t\t\t%d",i);
              break;
case 5: System.out.printf("\t\t\t\t\t%d",i);
              break;
case 6: System.out.printf("\t\t\t\t\t\t%d",i);
              break;
case 7: System.out.printf("\t\t\t\t\t\t\t%d",i);
              break;

}

h=8-a;
for(i=2;i<=h;i++)
{
   System.out.print("\t"+i);
}
System.out.print("\n");
for(i=h+1;i<=b;i++)
{
    if(check==7)
{
System.out.print("\n");
check=0;
}
System.out.print(" \t"+i);
check++;
}}
}   // "MAIN method ends here"
}   // "CLASS ends here"