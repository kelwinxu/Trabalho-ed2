#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main() {
    int movements = 0;
    int size = 5;
    int *towerInput = malloc(sizeof(int)*size);     //Input tower with unsorted weights
    towerInput[0] = 6;
    towerInput[1] = 2;
    towerInput[2] = 4;
    towerInput[3] = 3;
    towerInput[4] = 5;

    int *towerTemp = malloc(sizeof(int)*size);
    int *towerOutput = malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){                  //Create the other 2 empty Towers
        towerTemp[i] = -1;
        towerOutput[i] = -1;
    }

    printTowers(towerInput, towerTemp, towerOutput, size);

    recursiveDistinctQuicksort(towerInput, size);

    printTowers(towerInput, towerTemp, towerOutput, size);

    recursiveSolve(towerInput, towerTemp, towerOutput, size, &movements, towerInput, towerTemp, towerOutput);
    
    printTowers(towerInput, towerTemp, towerOutput, size);

    return 0;
}