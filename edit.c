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
            putchar('\n');
            // Check if the selected option was valid and is in the array's length
            if(option - 1 != -1 && option - 1 < size){
                // Clear terminal screen            
                clearScreen();
                char str[50];
                int isValid = 0;
                // Run forever
                while(1){
                    // Display available edit options
                    editOptions();
                    // Get user's input
                    getString(str, "Input", 50);
                    putchar('\n');
                    // Convert user's input to lowercase
                    toLowerStr(str);
                    // Check if quantity needs to be edited
                    if(strcmp(str, "quantity") == 0){
                        int input;
                        // Runs until a quantity greater than 0 has been entered
                        while(isValid != 1){
                            // Get user's input
                            getInt(&input, "Quantity");
                            // Check if input was valid
                            if(input == 0){
                                // Error message
                                printf("\nInvalid quantity!\nPlease try again.\n\n");
                            }
                            // Input was valid
                            else {
                                // Edit quantity
                                item[option-1].quantity = input;
                                // Break loop
                                isValid = 1;
                            }
                        }
                        // Update loop condition
                        isValid = 0;
                        // Clear terminal screen            
                        clearScreen();
                        printf("\nQuantity successfully edited!\n\n");
                    }
                    // Check if price needs to be edited
                    else if(strcmp(str, "price") == 0){
                        float input;
                        // Runs until a quantity greater than 0 has been entered
                        while(isValid != 1){
                            // Get user's input
                            getFloat(&input, "Price");
                            // Check if input was valid
                            if(input == 0){
                                // Error message
                                printf("\nInvalid price!\nPlease try again.\n\n");
                            }
                            // Input was valid
                            else {
                                // Edit price
                                item[option-1].price = input;
                                // Break loop
                                isValid = 1;
                            }
                        }
                        // Clear terminal screen            
                        clearScreen();
                        printf("\nPrice successfully edited!\n\n");
                    }
                    // Check if name needs to be edited
                    else if(strcmp(str, "name") == 0){
                        char newName[NAME];
                        // Get user's input
                        getString(item[option-1].name, "Name", NAME);
                        // Clear terminal screen            
                        clearScreen();
                        printf("\nName successfully edited!\n\n");
                    }
                    // Check if description needs to be
                    else if(strcmp(str, "description") == 0){
                        char newDesc[DESC];
                        // Get user's input
                        getString(item[option-1].description, "Description", DESC);
                        // Clear terminal screen            
                        clearScreen();
                        printf("\nDescription successfully edited!\n\n");
                    }
                    // Check if user would like to go back
                    else if(strcmp(str, "back") == 0){
                        break;
                    }
                    // Invalid input
                    else{
                        printf("Invalid input...\nPlease try again.\n\n");
                    }
                }
                // Clear terminal screen            
                clearScreen();
                printf("\nItem successfully edited!\n");
                break;
            }
            // Invalid option
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