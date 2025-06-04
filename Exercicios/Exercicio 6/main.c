#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/*
<main[0]> <algorithm[1]> <weights[2...n]>
*/

int main(int argc, char *argv[]) {
    if(argc == 1) return 1;

    int MAX_SIZE = argc-2;                      //Number of weights
    int movements = 0;                          //Movement number counter
    int weightMoved = 0;                        //Total weight moved counter

    if(argc == 2) MAX_SIZE = 7;                 //If no weights are given, use default test values

    Tower A = createEmptyTower('A', MAX_SIZE);  //Tower A: input tower
    A.size = MAX_SIZE;                          //Input tower starts full
    Tower B = createEmptyTower('B', MAX_SIZE);  //Tower B: temp tower
    Tower C = createEmptyTower('C', MAX_SIZE);  //Tower C: output tower
    
    if(argc == 2){                              //Default values
        A.disk[0] = 6;
        A.disk[1] = 2;
        A.disk[2] = 4;
        A.disk[3] = 3;
        A.disk[4] = 5;
        A.disk[5] = 9;
        A.disk[6] = 0;
    }else{
        char* end_pointer;
        for(int i = 2; i < argc; i++){          //Get weights from command line argv
            A.disk[i-2] = strtol(argv[i], &end_pointer, 10);
        }
    }

    if(strcmp(argv[1],"quick") == 0)
        recursiveDistinctQuicksort(A.disk, MAX_SIZE);
    else if(strcmp(argv[1],"heap") == 0)
        recursiveHeapSort(A.disk, MAX_SIZE);
    else
        return 2;

    recursiveSolve(&A, &B, &C, MAX_SIZE, &movements, &weightMoved);

    printf("Total weight moved = %d", weightMoved);
    
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