#include<stdio.h>
int main(){
    int i, q, x;
    float tax, gst, total = 0, itmp, result;

    printf("enter the no of items: ");
    scanf("%d", &i);

    printf("Item\tTotal\tPrice/Item\tItem Bill\n");
    for(x = 0; x < i; x++){
        printf("enter the item%d cost and quantity: ", x);
        scanf("%f %d", &itmp, &q);
        result = itmp * q;
        total += result;
        printf("Item%d\t%d\t%.2f\t\t%.2f\n", x, q, itmp, result);
    }

    tax = total * 0.05;
    gst = total + tax;

    printf("\nTotal\t\t\t\t%.2f\n", total);
    printf("Tax\t\t\t\t%.2f\n", tax);
    printf("Total Amount (with GST)\t\t%.2f\n", gst);

    return 0;
}
