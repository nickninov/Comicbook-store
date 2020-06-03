// Import libraries
#include <stdio.h>
#include <stdlib.h>

// Edit an item from the array
void editItem(struct item * item, int size){
    int option;
    // Check array's size
    if(size > 0){
        // Show the items in the array
        showProducts(item, size);
        // Run until a valid index has been chosen
        while(1){
            // Get user's input
            getInt(&option, "Index No̲");
            // Check if the selected option was valid and is in the array's length
            if(option - 1 != -1 && option - 1 < size){
                // Edit the selected product
                getItem(&item[option-1]);
                printf("\nItem successfully edited!\n");
                break;
            }
            else {
                printf("Invalid option...\nPlease try again.\n\n");
            }
        }
    }
    // Array is empty
    else {
        printf("No items to edit...\n");
    }
}