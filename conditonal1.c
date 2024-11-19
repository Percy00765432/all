#include <stdio.h>

void main() {
    int num1, num2, largest;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    largest = (num1 > num2) ? num1 : num2;

    printf("The larger number is: %d\n", largest);
}