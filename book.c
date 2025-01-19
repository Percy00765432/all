#include <stdio.h>
#include <string.h>

struct Bookinfo {
    char bname[30];
    int pages;
    float price;
} b[3];

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        printf("\nEnter the Name of Book: ");
        scanf("%29s", b[i].bname);  // Limit input to 29 characters to avoid buffer overflow
        printf("Enter the Number of Pages: ");
        scanf("%d", &b[i].pages);  // Use & to pass the address of the variable
        printf("Enter the Price of Book: ");
        scanf("%f", &b[i].price); // Use & to pass the address of the variable
    }

    printf("\n--------- Book Details ---------\n");
    for (i = 0; i < 3; i++) {
        printf("\nName of Book: %s", b[i].bname);
        printf("\nNumber of Pages: %d", b[i].pages);
        printf("\nPrice of Book: %.2f\n", b[i].price);  // Format price to 2 decimal places
    }

    return 0;
}
// Output:
// Enter the Name of Book: C Programming
// Enter the Number of Pages: 200
// Enter the Price of Book: 250
// Enter the Name of Book: Java Programming
// Enter the Number of Pages: 300
// Enter the Price of Book: 350
// Enter the Name of Book: Python Programming
// Enter the Number of Pages: 400
// Enter the Price of Book: 450
// --------- Book Details ---------
// Name of Book: C Programming
// Number of Pages: 200
// Price of Book: 250.00
