// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import files
#include "header.h"
#include "functions.c"
#include "edit.c"

// Display to the user the available options
void printOptions(void){
    printf("1) Exit program\n");
    printf("2) Add product\n");
    printf("3) Delete product\n");
    printf("4) Edit product\n");
    printf("5) Search product\n");
    printf("6) Save data\n");
    printf("7) Load data\n");
    printf("8) Show products\n\n");
}

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
                printf("Size before delete: %d\nSize after delete: %d\n\nIndex: %d\n\n", *size, (*size - 1), *index);


                // Check if elements need to be shifted
                if(option < *size - 1){
                    printf("Not the last item...\n\n");
                }

                // Decrement the array's size
                // *size -= 1;
                break;
            }
        }

    }
    // Array is empty
    else {
        printf("No items to delete...\n");
    }
}


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
            printf("Ealing's Comicbook Store\n\n");
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
                // deleteProduct(item, &size, &index);
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
                printf("Search product\n\n");
            }
            // Save data
            else if(option == 6){
                printf("Search product\n\n");
            }
            // Load saved data
            else if(option == 7){
                printf("Load data\n\n");
            }
            // Show data
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