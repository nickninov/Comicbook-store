// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Clear the terminal screen
void clearScreen(void){
    // Check if the computer is with a Windows - clear console
    #ifdef _WIN32
        system("cls");
    #else
        // Computer is either Linux or Mac - clear console
        system("clear");
    #endif
}

/* 
    Get up to a 10 digit integer from the user.
    Converts a string to an integer.
    option - pointer of integer to be modified
    txt - text ot be displayed on the console
*/
void getInt(int *option, char txt []){
    printf("%s: ", txt);
    char str_i[10];
    fgets(str_i, 10, stdin);
    *option = strtol(str_i, NULL, 10);
}

/* 
    Get up to a 10 digit float from the user.
    Converts a string to an integer.
    option - pointer of integer to be modified
    txt - text ot be displayed on the console
*/
void getFloat(float *option, char txt []){
    printf("%s: ", txt);
    char str_i[10];
    fgets(str_i, 10, stdin);
    *option = strtod(str_i, NULL);
}

/* 
    Get a string input from the user,
    str - char pointer to beginning of the char array
    txt - text to be displayed on the console
    num - the maximum number of characters that can be stored
*/
void getString(char * str, char txt[], int num) {
    printf("%s: ", txt);
    // Get user's input
    fgets(str, num, stdin);
    // Remove \n at the end
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = 0;
    }
}

// Display all items in the console
void showProducts(struct item * item, int size){
    // Check array's size
    if(size > 0){
        printf("---------------------------------------\n\n");
        printf("Products:\n\n");
        for(int i = 0; i < size; i++){
            printf("%d) Name: %s\n\n", (i+1), (item+i)->name);
            printf("Description: %s\n", (item+i)->description);
            printf("Quantity: %d\t\tPrice: £%.2f\n\n", (item+i)->quantity, (item+i)->price);
        }
        printf("---------------------------------------\n\n");
    }
    // Array is empty
    else {
        printf("No products...\n\n");
    }
}

// Get user's data for a single structure
void getItem(struct item * item){
    int isValid = 0;
    // Get user's input
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