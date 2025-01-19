#include <stdio.h>
#include <math.h>

int main() {
    int num, original_num, temp, digit, count = 0, sum = 0;


    printf("Enter a number: ");
    scanf("%d", &num);

    original_num = num;
    temp = num;
    while (temp != 0) {
        count++;
        temp /= 10;
    }


    temp = num;
    while (temp != 0) {
        digit = temp % 10;              
        sum += (int)pow(digit, count); 
        temp /= 10;                      
    }


    if (sum == original_num) {
        printf("%d is an Armstrong number.\n", original_num);
    } else {
        printf("%d is not an Armstrong number.\n", original_num);
    }

    return 0;
}