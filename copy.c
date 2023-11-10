#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct items
{
    char item[20];
    float price;
    int qty;
};
struct orders{
    char customer[50];
    char date[50];
    int number_of_items;
    struct items itm[50];
};
void generateheader(char name[50],char date[50])
{
        printf("\n\n");
        printf("  \t\t\t     NANI'S KITCHEN ");
        printf("\n\t\t\t-------------------------- ");
        printf("\n\tDate:%s",(date));
          
          printf("\n\tInvoice to:%s",(name));
           printf("\n--------------------------------------------------------------- ");
           printf("\nItems\t\t\t");
           printf("\t qty\t\t\t");
           printf("Total\t\t\t");
           printf("\n---------------------------------------------------------------");
           printf("\n\n");
}
 void generate_bill_body(char item[30],int *qty,float *price)
 {
    printf("%s\t\t\t\t",(item));
    printf("%d\t\t\t",(*qty));
    printf("%.2f\t\t\t",(*qty)*(*price));
    printf("\n");
 }
 void generate_bill_footer(float *t)
 {
    float total=*t;
      printf("\n");
      float dis=0.1*total;
      float net_total=total-dis;
      float cgst=0.09*net_total;
      float grand_total= net_total+2*cgst;
      printf("----------------------------------------------------------------------------\n");
      printf("\nSub total\t\t\t\t\t\t%.2f",total);
      printf("\nDiscount_@10%s\t\t\t\t\t\t%.2f","%",dis);
      
      printf("\nNet Total\t\t\t\t\t\t%.2f",net_total);
      printf("\nCGST_@9%s\t\t\t\t\t\t%.2f","%",cgst);
      printf("\nSGST_@9%s\t\t\t\t\t\t%.2f","%",cgst);
      printf("\n----------------------------------------------------------------------------");
      printf("\nGrand Total\t\t\t\t\t\t%.2f",grand_total);
      printf("\n-----------------------------------------------------------------------------");
 }

int main()
{
    int check=1;
    struct orders ord;  // for operating

     struct orders order;// for filr reading

    float total;
     int n;
    int opt;
    char name[50];
   FILE*fp;
   char savebill='y';
    //struct orders ord;
    // generateheader("Vignesh","2nd nov 2023");
    // generate_bill_body("pizza",2,249.9);   
    // generate_bill_footer(499);
    
    //dashboard
   do
   {

   printf("\t===================NANI'S KITCHEN===================");
    printf("\n\n Please Select the prefered operation:");
     printf("\n--------------------------------------------------------------");
   printf("\n1:Generate Invoice");
   printf("\n2:Show All Invoices");
   printf("\n3:Search Invoice");
   printf("\n4:Exit");
   
   printf("\n _YOUR CHOICE_:");
   scanf("%d",&opt);
  
   fgetc(stdin);// to consume the \n 
   switch(opt)
   {
    case 1:

         printf("\n Please enter the name of the customer:\t");
         scanf("%s",&name);
        strcpy(ord.customer,name);
        strcpy(ord.date,__DATE__);
        printf("Please enter the number of items ");
        scanf("%d",&n);
        ord.number_of_items=n;
        for(int i=1;i<=n;i++)
        {
            fgetc(stdin);
            printf("\n");
            printf("Please enter the item %d:",i);
            fgets(ord.itm[i].item,50,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Please enter the quantaty in units: ");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price: ");
            scanf("%f",&ord.itm[i].price);
            total+=ord.itm[i].qty*ord.itm[i].price;
        } 
         generateheader(ord.customer,ord.date);
         // body contains mor ethan one item
         for(int i=1;i<=ord.number_of_items;i++)
         {
            generate_bill_body(ord.itm[i].item,&ord.itm[i].qty,&ord.itm[i].price);
         }
             generate_bill_footer(&total);
             printf("\n DO you want to safe the in voice [1y/n] :");
             scanf("%s",&savebill);
             if(savebill=='y');
             {
               fopen("RESBILL.dat","a+");  // opening in append mode
               fwrite(&ord,sizeof(struct orders),1,fp);
               if(fwrite!=0)
               {
                printf("Sucessfully Saved");
               }
               else{
                printf("\n Error saving!!!");
               } 
               fclose(fp);
             }

           break;   /// case 1 breaks here

 
    fclose(fp);
    break;  
 
  case 2:
    fp=fopen("RESBILL.dat","r");
    printf("\n           *******Your Invoices*******");
    while(fread(&order,sizeof(struct orders),1,fp))
    { 
        generateheader(order.customer,order.date);
        for(int i=1;i<=order.number_of_items;i++)
        {
            generate_bill_body(order.itm[i].item,&order.itm[i].qty,&order.itm[i].price);
            total+=order.itm[i].qty * order.itm[i].price;
        }
        generate_bill_footer(&total);

    }
    break;
   }
   printf("\n Do you wish to continue :");
   scanf("%d",&check);
   } while(check);
   printf("\n\n");
    return 0;
}