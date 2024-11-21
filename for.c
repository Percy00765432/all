#include <stdio.h>
void main()
{
    int n,i;
    n=10;
    for(i=0;i<=n;i++)
    {
        if(i%2==0)
        {
            printf("%d \n",i);
        }
        else
        {
            printf("%d ",i);
        }
    }
}