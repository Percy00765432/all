#include <stdio.h>
int main() {
    int number, originalNumber, digit;
    int count = 0;
    int sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (number < 0) {
    number =-number; 
    }
    originalNumber = number;
    while (number > 0) {
    digit = number % 10; 
    sum=sum+digit; 
    count++;
    
    number = number/10;
    }
    printf("\nNumber: %d\n", originalNumber);
    printf("Number of digits: %d\n", count);
    printf("Sum of digits: %d\n", sum);
    return 0;
}