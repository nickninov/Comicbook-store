// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import files
#include "header.h"
#include "functions.c"
#include "edit.c"
#include "delete.c"
#include "search.c"
#include "file.c"

int main(){
    int option, size, capacity, index;
    
    // Initial heap memory 4 * sizeof(struct item)
    struct item * item = (struct item *) malloc(INITIAL_CAPACITY * itemSize);
    size = 0;
    index = 0;
    capacity = INITIAL_CAPACITY;
    
    // Check if memory has been allocated
    if(item != NULL){
        // Run forever
        while(1){
            printf("\nEaling's Comicbook Store\n\n");
            // Display options
            printOptions();
            // Get user's input
            getInt(&option, "Option");
            printf("\n");
            // Exit the program
            if(option == 1){
                // Clear terminal screen
                clearScreen();
                printf("Goodbye :)\n\n");
                free(item);
                return EXIT_SUCCESS;
            }
            // Add product to dynamic array
            else if(option == 2){
                // Clear terminal screen
                clearScreen();
                // Check if the current heap memory is greater than the current
                if(size == capacity){
                    // Double capacity
                    capacity *= 2;
                    // Increase dynamic memory
                    item = (struct item *) realloc(item, capacity * itemSize);
                }
                printf("Enter product details.\n\n");
                // Temporary structure that will store the details of the new product
                struct item newItem;
                // Get new product details
                getItem(&newItem);
                // Add new product to the array
                item[index] = newItem;
                // Increase the dynamic array's size
                size++;
                // Increment the index
                index++;
            }
            // Remove product
            else if(option == 3){
                // Clear terminal screen
                clearScreen();
                // Delete a product
                deleteProduct(item, &size, &index);
            }
            // Edit product
            else if(option == 4){
                // Clear terminal screen
                clearScreen();
                // Edit a selected item 
                editItem(item, size);
            }
            // Search for product
            else if(option == 5){
                // Clear terminal screen
                clearScreen();
                // Search for a product by it's name
                searchProduct(item, size);
            }
            // Save data
            else if(option == 6){
                // Clear terminal screen
                clearScreen();
                // Check if there is any data
                if(size > 0){
                    saveData(item, size);
                }
                else{
                    printf("No products to save...\n\n");
                }
            }
            // Load saved data
            else if(option == 7){
                // Clear terminal screen
                clearScreen();
                // Temporary new size
                int newSize;
                // File pointer
                FILE * fileP = fopen("data.bin", "rb");
                // Check if file exists
                if(fileP == NULL){
                    // Display error message - No such file or directory
                    perror("Error");
                }
                else{
                    // Read the number of records that will be
                    fread(&newSize, sizeof(int), 1, fileP);
                    // Double the capacity based on the read size of items
                    capacity = 2 * newSize;
                    item = (struct item *) realloc(item, capacity * itemSize);
                    fread(item, itemSize, newSize, fileP);
                    // Update current size
                    size = newSize;
                    // Update index to the last item
                    index = size;
                    // Success message
                    printf("File has been loaded successfully!\n\n");
                }
                // Close the file
                fclose(fileP);
            }
            // Show products
            else if(option == 8){
                // Clear terminal screen
                clearScreen();
                // Display the items inside the console
                showProducts(item, size);
            }
            // Invalid Option
            else {
                // Clear terminal screen
                clearScreen();
                printf("Invalid option...\nPlease try again.\n");
            }  
        }
    }
    // Memory has not been allocated
    else {
        printf("Memory could not be allocated...\n\n");
        return EXIT_FAILURE;
    }
    printf("\n");
}