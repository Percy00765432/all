#include <stdio.h>

// Function that takes pointers as parameters
void swapNumbers(int *a, int *b) {
    int temp = *a;    // Store value of first number in temp
    *a = *b;         // Put second number's value in first number
    *b = temp;       // Put temp (original first number) in second number
}

int main() {
    int x = 10;
    int y = 20;
    
    printf("Before swap:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
    // Pass addresses of x and y
    swapNumbers(&x, &y);
    
    printf("\nAfter swap:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
    return 0;
}