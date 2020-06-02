// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    fgets(str, num, stdin);
}

// Display all items in the console
void showProducts(struct item * item, int size){
    // int i = 0;
    if(size > 0){
        for(int i = 0; i < size; i++){
            printf("%d) Name: %s\n", (i+1), (item+i)->name);
            printf("Description: %s", (item+i)->description);
            printf("Quantity: %d\n", (item+i)->quantity);
            printf("Price: %.2f\n\n", (item+i)->price);
        }
    }
    else {
        printf("No products...\n");
    }
}