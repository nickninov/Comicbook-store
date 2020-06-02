// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import files
#include "header.h"
#include "functions.c"
#include "add.c"
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

int main(){
    int option, size, capacity, index;
    
    // Initial prodcut
    struct item * item = (struct item *) malloc(INITIAL_CAPACITY * itemSize);
    size = 0;
    index = 0;
    capacity = INITIAL_CAPACITY;

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
            printf("Enter product details.\n\n");
            struct item newItem;
            // Get new product details
            getItem(&newItem);
            // Add new product to the array
            addProduct(item, &index, newItem, &size, &capacity);
        }
        // Remove product
        else if(option == 3){
            printf("Remove product\n\n");
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
            printf("Products:\n\n");
            // Display the items inside the console
            showProducts(item, size);
        }
        // Invalid Option
        else {
            // Clear terminal screen
            clearScreen();
            printf("Invalid option...\nPlease try again.\n");
        }
        printf("\n-----------------------------\n\n");   
    }

}