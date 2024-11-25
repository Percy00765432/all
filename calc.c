#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a,b;
    float d;
    char op;
    printf("Enter the operation: ");
    scanf("%d%c%d",&a,&op,&b);
    switch(op)
    {
        case '+':
        printf("The sum of two numbers are: %d\n",a+b);
        break;
        case '-':
        printf("The difference of the two numbers are: %d\n",a-b);
        break;
        case '*':
        printf("The product of two numbers are: %d\n",a*b);
        break;
        case '/':
        if(b!=0){
            d=(float)a/b;
            printf("The division of the two numbers are: %.3f\n",d);
        }
        else
        printf("Invalid\n");
        break;
        default:
        printf("Invalid Input\n");
    }
}