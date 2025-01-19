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
 // At this point, the file is truncated and empty
    // Close the file
    fclose(file);
    printf("Content of 'example.txt' has been deleted.\n");
    return 0;
}
