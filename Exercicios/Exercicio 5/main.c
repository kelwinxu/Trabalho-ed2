#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]){
    if (argc != 3) {                                            // Check if the number of arguments is correct (function name + 2 strings)
        if(DEBUG) printf("ERROR: Not 3 parameters\n");
        return 1;                                               // Return error code (1 = parameter error)
    }
    if(DEBUG) printf("Uso: %s\n String 1:%s\n String 1:%s\n", argv[0], argv[1], argv[2]);

    char *inputString1 = argv[1];                               // Get the input string from command line arguments
    char *inputString2 = argv[2];

    if(strlen(inputString1) != strlen(inputString2)){
        if(DEBUG) printf("ERROR: Diferent size parameters\n");
        return 2;                                               // Return error code (2 = size error)
    }

    printf("Palavra 1: %s Palavra 2: %s Anagrama? ", inputString1, inputString2); // Print the input strings

    int size = strlen(inputString1);                            // Get the size of the input string

    int *array1 = stringToInt(inputString1);                    // Convert the input string to an array of integers
    int *array2 = stringToInt(inputString2);

    binaryInsertionSort(array1, size);                          // Sort the first array using binary insertion sort
    binaryInsertionSort(array2, size);                          // Sort the second array using binary insertion sort

    if (checkEqual(array1, array2, size) == 0) {                // Check if the two sorted arrays are equal
        printf("Sim\n");
    } else {
        printf("Não\n");
    }
    return 0;                                                   // Return success code (0 = success)
}