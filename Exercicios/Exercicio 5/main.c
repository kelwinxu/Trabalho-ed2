#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]){
    char *inputString1;                                         // Get the input string from command line arguments
    char *inputString2;
    if (argc == 3) {                                            // Check if the number of arguments is correct (function name + 2 strings)
        inputString1 = argv[1];                                 // Get the input string from command line arguments
        inputString2 = argv[2];
    } else {
        if(DEBUG) printf("ERROR: Not 3 parameters\n");
        isAnagram("pedro", "poder");
        isAnagram("Brasil", "brasileiro");
    }
    if(DEBUG) printf("Uso: %s\n String 1:%s\n String 1:%s\n", argv[0], argv[1], argv[2]);

    isAnagram(inputString1, inputString2);

    return 0;                                                   // Return success code (0 = success)
}