#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
#include "functions.h"

int main() {
    int movements = 0;
    int size = 5;
    Tower A;
    A->disk = malloc(sizeof(int)*size);     //Input tower with unsorted weights
    A->maxSize = size;
    A->disk[0] = 6;
    A->disk[1] = 2;
    A->disk[2] = 4;
    A->disk[3] = 3;
    A->disk[4] = 5;

    Tower B, C;
    B->disk = malloc(sizeof(int)*size);
    B->maxSize = size;
    C->disk = malloc(sizeof(int)*size);
    C->maxSize = size;
    for(int i = 0; i < size; i++){                  //Create the other 2 empty Towers
        B->disk[i] = -1;
        C->disk[i] = -1;
    }

    printTowers(towerInput, towerTemp, towerOutput, size);

    recursiveDistinctQuicksort(towerInput, size);

    printTowers(towerInput, towerTemp, towerOutput, size);

    recursiveSolve(towerInput, towerTemp, towerOutput, size, &movements, towerInput, towerTemp, towerOutput);
    
    printTowers(towerInput, towerTemp, towerOutput, size);

    return 0;
}