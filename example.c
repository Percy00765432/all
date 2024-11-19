#include <stdio.h>
void main()
{
    int a=1,b=3,c=7;
    a+=b*=c-=5;
    printf("%d",a);
}