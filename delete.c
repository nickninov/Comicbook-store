// Import libraries
#include <stdio.h>
#include <string.h>

// Deletes an item from the dynamic array
void deleteProduct(struct item * item, int * size, int * index){
    int option;
    // Check array's size
    if(*size > 0){
        while(1){
            // Display the products
            showProducts(item, *size);
            // Get the user's input
            getInt(&option, "Delete No̲");
            // Update option
            option -= 1;
            // Check if input was valid
            if(option == -1){
                // Clear terminal screen
                clearScreen();
                printf("Invalid option...\nPlease try again.\n\n");
            }
            // Check if input is inside the array
            if(option>= 0 && option < *size){
                // Check if elements need to be shifted
                if(option < *size - 1){
                    // Shift the items by 1 position
                    for(int i = option; i < *size; i++){
                        strcpy((item+i)->name, (item+i+1)->name);
                        strcpy((item+i)->description, (item+i+1)->description);
                        (item+i)->price = (item+i+1)->price;
                        (item+i)->quantity = (item+i+1)->quantity;
                    }
                }
                // Decrement the array's size
                *size -= 1;
                // Decrement the current index location
                *index -= 1;
                // Exit loop
                break;
            }
        }
    }
    // Array is empty
    else {
        printf("No items to delete...\n");
    }
}