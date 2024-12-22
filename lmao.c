#include <stdio.h>

// Recursive function to calculate GCD
int calculateGCD(int a, int b) {
    // Base case: if b becomes 0, a is the GCD
    if (b == 0)
        return a;
    
    // Recursive case: GCD(a,b) = GCD(b, a % b)
    return calculateGCD(b, a % b);
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);
    
    // Handle negative numbers by taking absolute value
    num1 = (num1 > 0) ? num1 : -num1;
    num2 = (num2 > 0) ? num2 : -num2;
    
    // Calculate and print GCD
    int gcd = calculateGCD(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);
    
    return 0;
}