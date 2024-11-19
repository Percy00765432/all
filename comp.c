#include<stdio.h>
void main()
{
    float f;
    printf("Enter the farenheit value: ");
    scanf("%f",&f);
    printf("The celsius value is %f", (f - 32) * 5 / 9);
}