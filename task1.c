#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char input[1000];

    // ----------- Step 1: Create and Write to File -----------
    file = fopen("internship_output.txt", "w");  // Open in writ
    if (file == NULL) {
        printf("❌ Error: Unable to create the file.\n");
        return 1;
    }

    printf("📝 Enter data to write to the file:\n> ");
    fgets(input, sizeof(input), stdin);  // Get input from user
    fputs(input, file);                  // Write to file
    fclose(file);
    printf("✅ Data written to 'internship_output.txt'\n\n");

    // ----------- Step 2: Append Data to File -----------
    file = fopen("internship_output.txt", "a");  // Open in appe
    if (file == NULL) {
        printf("❌ Error: Unable to open the file for appending.
        return 1;
    }

    printf("➕ Enter data to append to the file:\n> ");
    fgets(input, sizeof(input), stdin);
    fputs(input, file);
    fclose(file);
    printf("✅ Data appended successfully.\n\n");

    // ----------- Step 3: Read and Display File Content -------
    file = fopen("internship_output.txt", "r");  // Open in read
    if (file == NULL) {
        printf("❌ Error: Unable to read the file.\n");
        return 1;
    }

    printf("📖 Reading file content:\n\n");
    while (fgets(input, sizeof(input), file) != NULL) {
        printf("%s", input);  // Display file content
    }
    fclose(file);

    printf("\n✅ File operation completed successfully.\n");
    return 0;
}
