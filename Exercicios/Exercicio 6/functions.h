#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define DEBUG 0

//tower struct
typedef struct Tower_str{
char name;                  //Name for debug and print purposes
int maxSize;                //The max amount of disks
int size;                   //The current amount of disks
int *disk;                  //List of disks by weight, from top to bottom
} Tower;


//Sorting algorithms
    //Recursive function for quicksort algorithm with distinct numbers
    int* recursiveDistinctQuicksort(int* numbers, int size);
    //Recursive function for heap algorithm
    int* recursiveHeapsort(int* numbers);
    void heapify(int* numbers, int size, int i);
    void swap(int* a, int* b);

//Disk/Tower manipulation
    //Function to shift the whole array to the next index
    int shiftRight(Tower* tower);
    //Function to shift the whole array the the previous index
    int shiftRight(Tower* tower);
    //Function for moving disks between towers, return 0 if succeed
    int MoveDisk(Tower* towerFrom, Tower* towerTo);
    //Checks if the disk movement is valid (?)
    int validMovement(int* towerFrom, int* towerTo);
    //Prints the three towers
    int printTowers(Tower A, Tower B, Tower C);
    //Solve the tower of hanoi
    int recursiveSolve(Tower* towerFrom, Tower* towerTemp, Tower* towerTo, int size, int* movements);




#endif // FUNCTIONS_H