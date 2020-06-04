// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Returns 0 if char result[] is inside char name []
    Returns 1 if char result [] is not inside char name []
    name - the string that will be scanned
    result - the string that will be searched
*/
int doesMatch(char name[], char result[]){
    // Get string length for name and result
    int nameLength = strlen(name);
    int resultLength = strlen(result);
    // Allocate memory on the heap
    char * lowerName = (char *) malloc(nameLength * sizeof(char));
    char * lowerResult = (char *) malloc(resultLength * sizeof(char));
    // Check if memory was unsuccessfully allocated
    if(lowerName == NULL || lowerResult == NULL){
        // Free dynamically allocated memory
        free(lowerResult);
        free(lowerName);
        printf("Error while allocating memory for lowerResult and lowerName :/\n");
        return EXIT_FAILURE;
    }
    // Copy lower case name[] to dynamic memory
    for(int i = 0; i < nameLength; i++){
        lowerName[i] = tolower(name[i]);
    }
    // Copy lowercase result[] to dynamic memory
    for(int i = 0; i < resultLength; i++){
        lowerResult[i] = tolower(result[i]);
    }
    // Check if lowerResult occurs in lowerName
    char * substr = strstr(lowerName, lowerResult);
    // Free dynamically allocated memory
    free(lowerResult);
    free(lowerName);
    // Match has been found
    if(substr != NULL){
        return EXIT_SUCCESS;
    }
    // No match has been found
    return EXIT_FAILURE;
}

// Displays all products that match the user's input
void searchProduct(struct item * item, int size){
    char result [NAME];
    // To check if any matches are found
    int isEmpty = 1;

    // Check array's size
    if(size > 0){
        getString(result, "Product's name", NAME);
        printf("\n");
        // Display matched products
        for(int i = 0; i < size; i++){
            // Check for a match from current product's name and search result
            if(doesMatch((item+i)->name, result) == 0){
                // Display product
                printf("Name: %s\n\n", (item+i)->name);
                printf("Description: %s\n", (item+i)->description);
                printf("Quantity: %d\t\tPrice: £%.2f\n\n", (item+i)->quantity, (item+i)->price);
                // There is a match
                isEmpty = 0;
            }
        }
        // Check if a empty message needs to be displayed
        if(isEmpty == 1){
            printf("No match found...\n\n");
        }
    }
    // Array is empty
    else {
        printf("No products...\n");
    }
}