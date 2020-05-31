// Import libraries
#include <stdio.h>
#include <stdlib.h>

// Import files
#include "header.h"

// Clear the terminal's screen
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
*/
void getInt(int *option){
    char str_i[10];

    fgets(str_i, 10, stdin);
    *option = strtol(str_i, NULL, 10);
}