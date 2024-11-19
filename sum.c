#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum = sum+i;
    }
    printf("Sum of the first %d numbers is: %d\n", n, sum);
    return 0;
}