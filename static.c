#include <stdio.h>

void countLocal() {
    int localCounter = 0; // Local variable
    localCounter++;
    printf("Local Counter: %d\n", localCounter);
}

void countStatic() {
    static int staticCounter = 0; // Static variable
    staticCounter++;
    printf("Static Counter: %d\n", staticCounter);
}

int main() {
    printf("Using Local Variable:\n");
    countLocal(); // Output: Local Counter: 1
    countLocal(); // Output: Local Counter: 1
    countLocal(); // Output: Local Counter: 1

    printf("\nUsing Static Variable:\n");
    countStatic(); // Output: Static Counter: 1
    countStatic(); // Output: Static Counter: 2
    countStatic(); // Output: Static Counter: 3

    return 0;
}
