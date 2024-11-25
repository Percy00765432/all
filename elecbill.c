#include<stdio.h>
void main(){
    int units,total;
    printf("Enter the amount of units used: ");
    scanf("%d",&units);
    if(units<=50){
        total = units*4;}
    else if (units<=150){
        total= (50*4) + (units-50)*6; 
    }
    else if (units<=250)
    {
        total = (50*4) + (100*6) + (units-150)*7;
    }
    else{
        total = (50*4) + (100*6) + (100*7) + (units-250)*8;
    }
    total = total * 1.2;
    printf("\nThe total bill is rupees %d",total);
}