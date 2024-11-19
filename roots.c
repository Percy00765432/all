#include <stdio.h>
#include <math.h>
void main()
{
int a,b,c, d;
float root1,root2;
printf("Enter the coefficients of the equation: ");
scanf("%d%d%d",&a,&b,&c);
d=(b*b)-(4*a*c);
if(d>0){
root1=(-b+sqrt(d))/(2*a);
root2=(-b-sqrt(d))/(2*a);
printf("Two real and different roots are: %f , %f.\n",root1,root2);
}
else if(d==0){
root1=-b/(2*a);
root2=root1;
printf("Two real and equal roots are: %f and %f\n",root1,root2);
}
else{
float real,imaginary;
real=-b*(2*a);
imaginary=sqrt(fabs(d))/(2*a);
printf("Two imaginary roots are: %f+i%f and %f-i%f",real,imaginary,real,imaginary);
}
}
