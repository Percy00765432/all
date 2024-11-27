#include<stdio.h>
#include<math.h>
int main()
{
int start,end,num,original_num,remainder,n,result;
printf("Enter the start of the range: ");
scanf("%d",&start);
printf("Enter the end of the range: ");
scanf("%d",&end);
printf("Armstrong numbers between %d and %d are : \n",start,end);
for(num=start;num<=end;num++)
{
original_num=num;
result=0;
n=0;
while(original_num!=0)
{
original_num = original_num/10;
n++;
}
original_num=num;
while(original_num!=0)
{
remainder=original_num%10;
result +=pow(remainder,n);
original_num = original_num/10;
}
if(result==num)
printf("%d \t",num);
}
printf("\n");
return 0;
}
