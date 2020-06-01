// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import files
#include "header.h"
#include "functions.c"
#include "add.c"

// Display to the user the available options
void printOptions(void){
    printf("1) Exit program\n");
    printf("2) Add item\n");
    printf("3) Delete item\n");
    printf("4) Edit item\n");
    printf("5) Search item\n");
    printf("6) Save data\n");
    printf("7) Load data\n");
    printf("8) Show data\n\n");
}

int main(){
    int option, size, capacity, index;

    printf("Ealing's Comicbook Store\n\n");
    
    // Initial prodcut
    struct item * item = (struct item *) malloc(INITIAL_CAPACITY * sizeof(int));
    size = 0;
    index = 0;
    capacity = INITIAL_CAPACITY;

    // Run forever
    while(1){
        // Display options
        printOptions();
        
        // Get user's input
        getInt(&option, "Option");
        printf("\n");
        // Exit the program
        if(option == 1){
            printf("Goodbye :)\n\n");
            free(item);
            return EXIT_SUCCESS;
        }
        // Add product to dynamic array
        else if(option == 2){
            struct item newItem;
            getItem(&newItem);
            addProduct(item, &index, newItem, &size, &capacity);
        }
        // Remove product
        else if(option == 3){
            printf("Remove product\n\n");
        }
        // Edit product
        else if(option == 4){
            printf("Edit product\n\n");
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
            showProducts(item, size);
        }
        // Invalid Option
        else {
            clearScreen();
            printf("Invalid option...\nPlease try again.\n\n");
        }

        printf("\n-----------------------------\n\n");   
    }

}