#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

//Function declarations

//Converts a char to an integer
int* stringToInt(char *c);
//Converts a integer to a char
char* intToString(int *i);

//Sorts an array using the insertion sort algorithm + binary search
void binaryInsertionSort(int *array1, int size);
//Checks if two arrays are equal
int checkEqual(int *array1, int *array2, int size);

#endif // FUNCTIONS_H