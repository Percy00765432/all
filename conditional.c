#include<stdio.h>
void main(){
    int number1, number2,max;
    printf("enter two number : ");
    scanf("%d%d",&number1, &number2);
    max =(number1 > number2) ? number1 : number2;

    printf("the max of 2 numbers is : %d \n",max);
}