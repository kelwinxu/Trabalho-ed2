#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "functions.h"
#define MAX_SIZE 5

int main() {
    int movements = 0;
    Tower A;                               //Tower A: input tower
    A.name = 'A';
    A.disk = malloc(sizeof(int)*MAX_SIZE);     //Input tower with unsorted weights
    A.maxSize = MAX_SIZE;
    A.disk[0] = 6;
    A.disk[1] = 2;
    A.disk[2] = 4;
    A.disk[3] = 3;
    A.disk[4] = 5;
    A.size = 5;

    Tower B, C;                             //Tower B/C: temp/output tower
    B.disk = malloc(sizeof(int)*MAX_SIZE);
    B.maxSize = MAX_SIZE;
    B.name = 'B';
    C.disk = malloc(sizeof(int)*MAX_SIZE);
    C.maxSize = MAX_SIZE;
    C.name = 'C';
    for(int i = 0; i < MAX_SIZE; i++){                  //Create the other 2 empty Towers
        B.disk[i] = -1;
        C.disk[i] = -1;
    }

    printTowers(A, B, C);

    recursiveDistinctQuicksort(A.disk, MAX_SIZE);

    printf("Quicksort: weights sorted! \n");

    printTowers(A, B, C);

    recursiveSolve(&A, &B, &C, 5, &movements);

    printTowers(A, B, C);
    
/*
    shiftRight(&A);
    printTowers(A, B, C);
    shiftLeft(&A);
    printTowers(A, B, C);
    MoveDisk(&A, &B);
    printTowers(A, B, C);
*/

    return 0;
}