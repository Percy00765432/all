#include<stdio.h>
int main()
{
int a, b ,r, n1, n2, gcd,lcm;
printf("Enter two numbers: ");
scanf("%d %d",&n1,&n2);
a=n1;
 b=n2;
 while(n2!=0){
 r=n1%n2;
 n1=n2;
 n2=r;
 }
 gcd=n1;
 printf("gcd=%d\n",gcd);
 lcm=(a*b)/gcd;
 printf("lcm=%d",lcm);
}