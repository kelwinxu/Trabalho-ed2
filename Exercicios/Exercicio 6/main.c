#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "functions.h"
#define MAX_SIZE 7

int main() {
    int movements = 0;
    Tower A = createEmptyTower('A', MAX_SIZE);  //Tower A: input tower
    A.maxSize = MAX_SIZE;
    A.disk[0] = 6;
    A.disk[1] = 2;
    A.disk[2] = 4;
    A.disk[3] = 3;
    A.disk[4] = 5;
    A.disk[5] = 9;
    A.disk[6] = 0;
    A.size = MAX_SIZE;

    Tower B = createEmptyTower('B', MAX_SIZE);  //Tower B: temp tower
    Tower C = createEmptyTower('C', MAX_SIZE);  //Tower C: output tower                                   

    recursiveHeapSort(A.disk, MAX_SIZE);

    recursiveSolve(&A, &B, &C, MAX_SIZE, &movements);
    
/*
    shiftRight(&A);
    printTowersABC(A, B, C);
    shiftLeft(&A);
    printTowersABC(A, B, C);
    MoveDisk(&A, &B);
    printTowersABC(A, B, C);
*/
    freeTower(&A);
    freeTower(&B);
    freeTower(&C);
    return 0;
}