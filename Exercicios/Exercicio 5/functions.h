#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

//Function declarations

//Converts a char to an integer (not case sensitive), returns an array of integers
int* stringToInt(char *c, int size);
//Converts a integer to a char, returns a string of characters // Not used
char* intToString(int *i);

//Sorts an array using the insertion sort algorithm + binary search
void binaryInsertionSort(int *array1, int size);
//Checks if two arrays are equal
int checkEqual(int *array1, int *array2, int size);
//Prints if two strings are anagrams, return 0 if success
int isAnagram(char *inputString1, char *inputString2);

#endif // FUNCTIONS_H