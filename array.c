#include <stdio.h>

void main() {
    int a;
    printf("Enter a number to print its multiplication table: ");
    scanf("%d", &a);
    printf("Multiplication Table for %d:\n", a);
    for(int i = 1; i <= 10; i++) 
    {
        printf("%d x %d = %d\n", a, i, a * i);
    }
}
