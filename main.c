// Import libraries
#include <stdio.h>
#include <stdlib.h>

// Import files
#include "header.h"
#include "functions.c"

// Display to the user the available options
void printOptions(void){
    printf("1) Exit program\n");
    printf("2) Add item\n");
    printf("3) Delete item\n");
    printf("4) Edit item\n");
    printf("5) Search item\n\n");
}

// Display the user the menu and get the user's input
void menuOption(void) {
    
    int option;
    
    // Display options
    printOptions();
    
    // Get user's input
    printf("Option: ");
    getInt(&option);


    switch(option){
        // Invalid option
        case 0:
            clearScreen();
            printf("Invalid option...\nPlease try again.\n\n");
            menuOption();
            break;
        // Exit the program
        case 1:
            printf("Goodbye :)\n\n");
            system(EXIT_SUCCESS);
            break;
        // Add product
        case 2:
            printf("Add product\n\n");
            menuOption();
            break;
        // Remove product
        case 3:
            printf("Remove product\n\n");
            menuOption();
            break;
        // Edit product
        case 4:
            printf("Edit product\n\n");
            menuOption();
            break;
        // Search for product
        case 5:
            printf("Search product\n\n");
            menuOption();
            break;
    }
}

int main(){
    printf("Ealing's Comicbook Store\n\n");
    menuOption();
}