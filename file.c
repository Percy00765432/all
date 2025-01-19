#include <stdio.h>

int main() {
    // File pointer declaration
    FILE *file;
    char buffer[100];
    // 1. Creating a new file and writing to it
    file = fopen("example.txt", "w"); // Create or truncate the file for writing
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(file, "Hello, world!\nThis is a sample file.\n");
    fclose(file); // Close the file
    // 2. Opening an existing file and reading from it
    file = fopen("example.txt", "r"); // Open for reading
    if (file == NULL) {
 perror("Error opening file");
        return 1;
    }
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Read and print each line
    }
    fclose(file); // Close the file 
// 3. Opening a file for updating (read and write)
    file = fopen("example.txt", "r+"); // Open for reading and writing
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
// 4. Moving to a specific location and writing
    fseek(file, 0, SEEK_SET); // Move to the beginning of the file
    fprintf(file, "Hello\n"); // Write at the beginning
    fclose(file); // Close the file
    // 5. Re-reading to verify changes
    file = fopen("example.txt", "r"); // Reopen for reading
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    printf("\nUpdated File contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Read and print each line
    }
    fclose(file); // Close the file
    return 0;
}