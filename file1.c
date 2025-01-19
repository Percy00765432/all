#include <stdio.h>
int main() {
    // File pointer
    FILE *file;
    char buffer[256]; // Buffer to hold data read from the file
    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
// Read and print the file content line by line
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Print each line read from the file
    }
    // Close the file
    fclose(file);
    return 0;
}
