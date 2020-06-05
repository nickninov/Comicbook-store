// Import libraries
#include <stdio.h>
#include <stdlib.h>

// Save the data in a file
void saveData(struct item * item, int size){
    // File pointer
    FILE * fP = fopen("data.bin", "wb");
    // Check if file exists
    if(fP != NULL){
        // Store the number of records that will be saved
        fwrite(&size, sizeof(int), 1, fP);
        // Store the data in the file
        fwrite(item, itemSize, size, fP);
        // Success message
        printf("Data saved successfully!\n\n");
    }
    // File could not be created
    else{
        printf("File could not be created...\n\n");
        exit(EXIT_FAILURE);
    }
    // Close the file
    fclose(fP);
}