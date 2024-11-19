#include <stdio.h>
#include <conio.h>

int main() {
    char ch;

    printf("Press any key to continue...\n");
    ch = getch(); 

    printf("You pressed: %c\n", ch);

    return 0;
}