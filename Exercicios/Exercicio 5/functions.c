#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int* stringToInt(char *c, int size){
    int *array1 = (int*)malloc(sizeof(int) * strlen(c));    // Allocate memory for the array of integers
    for (int i = 0; i < size; i++) {                        // For each character in the string
        if(c[i] >= 'a' && c[i] <= 'z') {                    // Check if the character is a lowercase letter
            array1[i] = (int)(c[i] - 'a');                  // Convert the character to an integer
        } else if(c[i] >= 'A' && c[i] <= 'Z') {             // Check if the character is an uppercase letter
            array1[i] = (int)(c[i] - 'A');                  // Convert the character to an integer
        } else {
            if(DEBUG) printf("ERROR: Invalid character\n");
            return NULL;                                    // Return NULL if the character is not a letter
        }

    }
    return array1;                                          // Return the array
}

char* intToString(int *i){
    char *c = (char*)malloc(sizeof(char) * 100);            // Allocate memory for the string
    for (int j = 0; j < 100; j++) {                         // For each element in the array
        c[j] = (char)(i[j] + 'a');                                  // Convert the integer to a character
    }
    return c;                                               // Return the string
}   

/*General algorithm idea (insertion sort):
Starts with the first element of the array as sorted.
Then, for each subsequent element, it finds the correct position in the sorted part of the array using binary search.
Once the position is found, it shifts all larger elements to the right and inserts the current element at its correct position.
The binary search is used to find the correct position for the current element in the sorted part of the array.

Example:
Suppose we have the following array:
Array: [3, 1, 4, 2]  ->  Sorted part: [3]
The first element (3) is considered sorted.
The second element (1) is compared with the sorted part (3) using binary search.
The binary search finds that 1 should be placed before 3.
Array: [1, 3, 4, 2]  -> Sorted part: [1, 3]
The third element (4) is already in the correct position, so no changes are made.
Array: [1, 3, 4, 2]  -> Sorted part: [1, 3, 4]
The fourth element (2) is compared with the sorted part (1, 3, 4) using binary search.
The binary search finds that 2 should be placed between 1 and 3.
Array: [1, 2, 3, 4] -> Sorted part: [1, 2, 3, 4] -> Sorted array: [1, 2, 3, 4]
The algorithm continues until all elements are sorted.
*/


void binaryInsertionSort(int *array1, int size){
    int i, j, key;                                  // Index for the current element, index for the previous element, and key for insertion,
    for (i = 1; i < size; i++) {                    // Obs.: The first element is already sorted
        key = array1[i];                            // The current element to be inserted
        j = i - 1;                                  // Index for the last sorted element

        // Binary search to find the correct position for the key
        int left = 0, right = j;                    // Initialize left and right pointers for binary search 
        while (left <= right) {                     // While there are elements to search
            int mid = left + (right - left) / 2;    // Calculate the middle index
            if (array1[mid] > key) {                // If the middle element is greater than the key, search in the left half
                right = mid - 1;
            } else { 
                left = mid + 1;
            }
        }

        // Move elements to make space for the key
        while (j >= left) {                         // While there are elements to move
            array1[j + 1] = array1[j];              // Move the element to the right
            j--;                                    // Move pointer to the left
        }
        array1[left] = key;                         // Insert the key at the correct position
        if(DEBUG) {
            printf("Inserted %d at position %d\n", key, left);
            printf("Current array: ");
            for (int k = 0; k < size; k++) {
                printf("%d ", array1[k]);
            }
        }
    }
}

int checkEqual(int *array1, int *array2, int size){
    for (int i = 0; i < size; i++) {                // For each element in the array
        if (array1[i] != array2[i]) {               // If the elements are not equal
            return 1;                               // Return false
        }
    }
    return 0;                                       // Return true
}

int isAnagram(char *inputString1, char *inputString2){
    if(strlen(inputString1) != strlen(inputString2)){
        if(DEBUG) printf("ERROR: Diferent size parameters\n");
        printf("Palavra 1: %s Palavra 2: %s Anagrama? Nao", inputString1, inputString2); // Print the input strings
        return 0;                                               // Return error code (1 = str size error)  // runcodes wont allow this, so return 0
    }

    printf("Palavra 1: %s Palavra 2: %s Anagrama? ", inputString1, inputString2); // Print the input strings

    int size = (int)strlen(inputString1);                       // Get the size of the input string

    int *array1 = stringToInt(inputString1, size);              // Convert the input string to an array of integers
    int *array2 = stringToInt(inputString2, size);

    binaryInsertionSort(array1, size);                          // Sort the first array using binary insertion sort
    binaryInsertionSort(array2, size);                          // Sort the second array using binary insertion sort

    if (checkEqual(array1, array2, size) == 0) {                // Check if the two sorted arrays are equal
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    free(array1);                                               // Free the memory allocated for the arrays
    free(array2);
    return 0;                                                   // Return success code (0 = success)
}


