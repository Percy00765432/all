#include <stdio.h>


int calculateGCD(int a, int b) {
    
    if (b == 0)
        return a;
    
    
    return calculateGCD(b, a % b);
}

int main() {
    int num1, num2;
    
    
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);
    
    
    num1 = (num1 > 0) ? num1 : -num1;
    num2 = (num2 > 0) ? num2 : -num2;
    
    
    int gcd = calculateGCD(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);
    
    return 0;
}