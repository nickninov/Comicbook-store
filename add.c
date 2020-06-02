// Import libraries
#include <stdio.h>
#include <stdlib.h>

// Get user's data for a single structure
void getItem(struct item * item){
    int isValid = 0;
    getString((*item).name, "Name", NAME);

    getString((*item).description, "Description", DESC);

    // Runs until a quantity greater than 0 has been entered
    while(isValid != 1){
        // Get user's input
        getInt(&item->quantity, "Quantity");

        // Check if input was valid
        if(item->quantity == 0){
            // Error message
            printf("\nInvalid quantity!\nPlease try again.\n\n");
        }
        // Input was valid
        else {
            // Break loop
            isValid = 1;
        }
    }
    
    // Update loop condition
    isValid = 0;

    // Runs until a quantity greater than 0 has been entered
    while(isValid != 1){
        // Get user's input
        getFloat(&item->price, "Price");

        // Check if input was valid
        if(item->price == 0){
            // Error message
            printf("\nInvalid price!\nPlease try again.\n\n");
        }
        // Input was valid
        else {
            // Break loop
            isValid = 1;
        }
    }
}

// Add an item to the product list
void addProduct(struct item * item, int * index, struct item newItem, int *size, int *capacity){
    // Check if the dynamic array's size is greater than the current capacity
    if(*size > *capacity){
        // Increase the capacity of the current array
        struct item * newP = (struct item *) realloc(item, sizeof(item) * 2);
        // Make the current array structure point to the new location
        item = newP;
        // Double the capacity
        *capacity = sizeof(item) * 2;
    }
    // Push new item at the end
    item[*index] = newItem;
    // Increment the size and index of the array
    *size += 1;
    *index += 1;
    printf("\nItem has been added successfully!\n");
}