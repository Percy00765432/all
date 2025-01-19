#include <stdio.h>
int main() {
    // File pointer
    FILE *file;
    // Open the file for writing
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
// Write some content to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a simple C program that writes to a file.\n");
    fprintf(file, "You can add more lines or data as needed.\n");
    // Close the file
    fclose(file);
    printf("Content successfully written to output.txt\n");
    return 0;
}
