#include<stdio.h>
int main()
{
int x,i,a,b,q;
float tax,gst,total,itmp,result;
printf("enter the no of items");
scanf("%d",&i);
for(x=1;x<=i;x++)
{
printf("enter the item %d cost and quantity: ",x);
scanf("%f %d",&itmp,&q);
result=itmp*q;
total=total+result;
}
printf("the total cost is:%.2f",total);

 return 0;
  
 }